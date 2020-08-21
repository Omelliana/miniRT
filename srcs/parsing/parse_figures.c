/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 02:06:02 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 21:56:29 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_sphere(t_scene *scene, t_fline line)
{
	t_sphere	*sphere;
	t_object	*object;

	if (ft_sstrlen(line.parse) != 4)
		error_exit("|Wrong sphere parameters|");
	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		error_exit("|Sphere malloc error|");
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error_exit("|Sphere object malloc error|");
	sphere->coord = parse_axis(line.parse[1], 0);
	sphere->radius = ft_atof(line.parse[2]) / 2;
	if (sphere->radius < 0)
		error_exit("|Sphere diameter can't negative|");
	object->color = parse_frgb(line.parse[3]);
	object->type = SPHERE;
	object->ptr = sphere;
	ft_lstadd_back(&scene->obj_list, ft_lstnew(object));
}

void			parse_plane(t_scene *scene, t_fline line)
{
	t_plane		*plane;
	t_object	*object;

	if (ft_sstrlen(line.parse) != 4)
		error_exit("|Wrong plane parameters|");
	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		error_exit("|Plane malloc error|");
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error_exit("|Plane object  malloc error|");
	plane->coord = parse_axis(line.parse[1], 0);
	plane->vector = parse_axis(line.parse[2], 1);
	object->color = parse_frgb(line.parse[3]);
	object->type = PLANE;
	object->ptr = plane;
	ft_lstadd_back(&scene->obj_list, ft_lstnew(object));
}

void			parse_square(t_scene *scene, t_fline line)
{
	t_square	*square;
	t_object	*object;

	if (ft_sstrlen(line.parse) != 5)
		error_exit("|Wrong square parameters|");
	if (!(square = (t_square *)malloc(sizeof(t_square))))
		error_exit("|Square malloc error|");
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error_exit("|Square object malloc error|");
	square->coord = parse_axis(line.parse[1], 0);
	square->vector = parse_axis(line.parse[2], 1);
	square->size = ft_atof(line.parse[3]);
	if (square->size <= 0)
		error_exit("|Wrong size of square|");
	object->color = parse_frgb(line.parse[4]);
	object->type = SQUARE;
	object->ptr = square;
	ft_lstadd_back(&scene->obj_list, ft_lstnew(object));
}

void			parse_triangle(t_scene *scene, t_fline line)
{
	t_triangle	*triangle;
	t_object	*object;

	if (ft_sstrlen(line.parse) != 5)
		error_exit("|Wrong trinagle parameters|");
	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		error_exit("|Triangle malloc error|");
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error_exit("|Trinagle object malloc error|");
	triangle->first = parse_axis(line.parse[1], 0);
	triangle->second = parse_axis(line.parse[2], 0);
	triangle->third = parse_axis(line.parse[3], 0);
	object->color = parse_frgb(line.parse[4]);
	object->type = TRIANGLE;
	object->ptr = triangle;
	ft_lstadd_back(&scene->obj_list, ft_lstnew(object));
}

void			parse_cylindr(t_scene *scene, t_fline line)
{
	t_cylindr	*cylindr;
	t_object	*object;

	if (ft_sstrlen(line.parse) != 6)
		error_exit("|Wrong cylinder parameters|");
	if (!(cylindr = (t_cylindr *)malloc(sizeof(t_cylindr))))
		error_exit("|Cylinder malloc error|");
	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error_exit("|Cylinder object malloc error|");
	cylindr->coord = parse_axis(line.parse[1], 0);
	cylindr->vector = parse_axis(line.parse[2], 1);
	cylindr->radius = ft_atof(line.parse[3]) / 2;
	if (cylindr->radius < 0)
		error_exit("|Cylinder diameter can't negative|");
	cylindr->height = ft_atof(line.parse[4]);
	if (cylindr->height < 0)
		error_exit("|Cylinder height can't negative|");
	object->color = parse_frgb(line.parse[5]);
	object->type = CYLINDER;
	object->ptr = cylindr;
	ft_lstadd_back(&scene->obj_list, ft_lstnew(object));
}
