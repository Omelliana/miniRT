/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:41:20 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/14 22:10:23 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_axis	build_ray(t_scene *scene, int x, int y, t_camera camera)
{
	double		cam_x;
	double		cam_y;
	double		fov;
	double		ratio;

	fov = tan((double)camera.fov / 2 * M_PI / 180);
	ratio = (double)scene->res.x / (double)scene->res.y;
	cam_x = (2 * ((x + 0.5) / (double)scene->res.x) - 1) * ratio * fov;
	cam_y = (1 - 2 * ((y + 0.5) / (double)scene->res.y)) * fov;
	return (init_vector(cam_x, cam_y, 1));
}

t_ray			create_ray(t_axis start, t_axis direct)
{
	t_ray		ray;

	ray.start = start;
	ray.direct = direct;
	return (ray);
}

t_ray			get_ray(int x, int y, t_scene *scene)
{
	t_axis		origin;
	t_axis		direct;
	t_matrix	matrix;
	t_camera	camera;

	camera = switch_camera(scene);
	matrix = view(camera.vector, camera.coord);
	origin = matrix_multiply(init_vector(0, 0, 0), matrix);
	direct = build_ray(scene, x, y, camera);
	direct = matrix_multiply(direct, matrix);
	direct = vector_difference(direct, origin);
	normal(&direct);
	return (create_ray(origin, direct));
}
