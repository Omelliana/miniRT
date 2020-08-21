/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:13:42 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/14 19:02:41 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera		switch_camera(t_scene *scene)
{
	int			i;
	t_list		*camera;

	i = -1;
	camera = scene->cam_list;
	while ((++i < scene->camera) && (camera))
		camera = camera->next;
	return (*(t_camera *)camera->content);
}
