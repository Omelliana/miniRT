/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 00:29:20 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 23:23:23 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_axis		get_sphere_normal(t_axis point, t_sphere sphere)
{
	t_axis			n;

	n = vector_difference(point, sphere.coord);
	normal(&n);
	return (n);
}

static t_axis		get_plane_square_normal(t_plane plane,
					t_square square, t_object *object)
{
	t_axis			res;

	res = (object->type == SQUARE) ? square.vector : plane.vector;
	return (res);
}

static t_axis		get_triangle_normal(t_triangle triangle)
{
	t_axis			a;
	t_axis			b;
	t_axis			c;

	a = vector_difference(triangle.second, triangle.first);
	b = vector_difference(triangle.third, triangle.first);
	c = perpendicul_vec(a, b);
	normal(&c);
	return (c);
}

static t_axis		get_cylinder_normal(t_axis point, t_cylindr cylinder)
{
	t_axis			ctp;
	t_axis			norm;

	ctp = vector_difference(point, cylinder.coord);
	norm = vector_difference(ctp, vector_multiply(cylinder.vector,
										vector_dot(cylinder.vector, ctp)));
	normal(&norm);
	return (norm);
}

t_axis				get_normal(t_axis point, t_object *object)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(point, *(t_sphere *)object->ptr));
	else if ((object->type == SQUARE) || (object->type == PLANE))
		return (get_plane_square_normal(*(t_plane *)object->ptr,
							*(t_square *)object->ptr, object));
	else if (object->type == TRIANGLE)
		return (get_triangle_normal(*(t_triangle *)object->ptr));
	else
		return (get_cylinder_normal(point, *(t_cylindr *)object->ptr));
}
