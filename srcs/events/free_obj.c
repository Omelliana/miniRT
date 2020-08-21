/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:18:40 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/14 18:31:50 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}

void		free_sstr(char **line)
{
	int		ind;

	ind = -1;
	while (line[++ind])
		ft_strdel(&line[ind]);
	free(line);
	line = NULL;
}

void		free_parse(t_fline *line)
{
	free_sstr(line->parse);
	ft_strdel(&line->gnl);
}

void		free_struct(t_scene *scene)
{
	ft_lstclear(&scene->cam_list, free);
	ft_lstclear(&scene->light_list, free);
	ft_lstclear(&scene->obj_list, free);
	free(scene);
	scene = NULL;
}
