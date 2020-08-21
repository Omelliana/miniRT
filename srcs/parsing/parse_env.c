/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 23:41:03 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 13:39:02 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		parse_resolution(t_scene *scene, t_fline line)
{
	int			sizex;
	int			sizey;

	if (scene->res.x != 0)
		error_exit("|Resolution's already specified|");
	if (ft_sstrlen(line.parse) != 3)
		error_exit("|Wrong resolution parameters|");
	scene->res.x = ft_atoi(line.parse[1]);
	scene->res.y = ft_atoi(line.parse[2]);
	if ((scene->res.x < 1) || (scene->res.y < 1))
		error_exit("|Resolution is too small|");
	if ((scene->res.x > 7680) || (scene->res.y > 4320))
		error_exit("|Resolution is too big|");
	mlx_get_screen_size(&sizex, &sizey);
	scene->res.x = scene->res.x > sizex ? sizex : scene->res.x;
	scene->res.y = scene->res.y > sizey ? sizey : scene->res.y;
	if (!scene->save)
		scene->res.y = (scene->res.y == sizey)
		|| (scene->res.y > sizey - 20) ? sizey - 20 : scene->res.y;
}

static void		parse_ambient(t_scene *scene, t_fline line)
{
	if (scene->amb.rgb.r != -1)
		error_exit("|Ambient's already specified|");
	if (ft_sstrlen(line.parse) != 3)
		error_exit("|Wrong ambient light parameters|");
	scene->amb.ratio = ft_atof(line.parse[1]);
	if ((scene->amb.ratio < 0) || (scene->amb.ratio > 1))
		error_exit("|Ambient light ratio range in [0.0,1.0]|");
	scene->amb.rgb = parse_frgb(line.parse[2]);
}

static void		parse_camera(t_scene *scene, t_fline line)
{
	t_camera	*cam;

	if (ft_sstrlen(line.parse) != 4)
		error_exit("|Wrong camera parameters|");
	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		error_exit("|Camera malloc error|");
	cam->coord = parse_axis(line.parse[1], 0);
	cam->vector = parse_axis(line.parse[2], 1);
	if (cam->vector.z == 0 && cam->vector.x == 0 && cam->vector.y == 0)
		cam->vector.z = 1;
	else if (cam->vector.z == 0)
		cam->vector.z += 0.01;
	cam->fov = ft_atoi(line.parse[3]);
	if ((cam->fov < 0) || (cam->fov > 180))
		error_exit("|Camera FOV range in [0, 180]|");
	ft_lstadd_back(&scene->cam_list, ft_lstnew(cam));
}

static void		parse_light(t_scene *scene, t_fline line)
{
	t_light		*ligth;

	if (ft_sstrlen(line.parse) != 4)
		error_exit("|Wrong light parameters|");
	if (!(ligth = (t_light *)malloc(sizeof(t_light))))
		error_exit("|Light malloc error|");
	ligth->coord = parse_axis(line.parse[1], 0);
	ligth->bright = ft_atof(line.parse[2]);
	if ((ligth->bright < 0) || (ligth->bright > 1))
		error_exit("|Light brightness ratio range [0.0, 1.0]|");
	ligth->rgb = parse_frgb(line.parse[3]);
	ft_lstadd_back(&scene->light_list, ft_lstnew(ligth));
}

void			parse_env(t_scene *scene, t_fline line, char *param)
{
	if (!ft_strcmp(param, "R"))
		parse_resolution(scene, line);
	else if (!ft_strcmp(param, "A"))
		parse_ambient(scene, line);
	else if (!ft_strcmp(param, "c"))
		parse_camera(scene, line);
	else
		parse_light(scene, line);
}
