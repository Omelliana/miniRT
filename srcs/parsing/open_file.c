/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:14:03 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 16:01:52 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_scene	*create_scene(void)
{
	t_scene		*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		error_exit("|Scene malloc error|");
	scene->res.x = 0;
	scene->res.y = 0;
	scene->cam_list = NULL;
	scene->light_list = NULL;
	scene->obj_list = NULL;
	scene->save = 0;
	scene->filter = 0;
	scene->amb.rgb.r = -1;
	scene->amb.rgb.g = -1;
	scene->amb.rgb.b = -1;
	return (scene);
}

static void		scene_errors(t_scene *scene)
{
	if (scene->res.x == 0 || scene->res.y == 0)
		error_exit("|Specify resolution for scene|");
	if (scene->cam_list == NULL)
		error_exit("|Need at least one camera in a scene|");
	if (scene->obj_list == NULL)
		error_exit("|Need at least one object in a scene|");
	if (scene->amb.rgb.r == -1)
		error_exit("|Specify ambient for scene|");
}

static void		line_parse(t_fline line, t_scene *scene)
{
	line.parse = ft_split_set(line.gnl, SP);
	if (line.parse[0])
		parse(scene, line, line.parse[0]);
	free_parse(&line);
}

t_scene			*open_file(char *file_name, int save)
{
	int			fd;
	int			res;
	t_fline		line;
	t_scene		*scene;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		error_exit("|Fails to open scene|");
	scene = create_scene();
	scene->save = save == 1 ? 1 : 0;
	while ((res = get_next_line(fd, &line.gnl)) > 0)
		line_parse(line, scene);
	(res < 0) ? error_exit("|Fails to read from file|") : NULL;
	line_parse(line, scene);
	scene_errors(scene);
	close(fd);
	return (scene);
}
