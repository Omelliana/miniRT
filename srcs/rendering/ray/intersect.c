/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:07:01 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 22:18:38 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		intersect(t_ray ray, t_object *object, double *t)
{
	if (object->type == SPHERE)
		return (intersect_sphere(*(t_sphere *)object->ptr, ray, t));
	else if (object->type == PLANE)
		return (intersect_plane(*(t_plane *)object->ptr, ray, t));
	else if (object->type == SQUARE)
		return (intersect_square(*(t_square *)object->ptr, ray, t));
	else if (object->type == TRIANGLE)
		return (intersect_triangle(*(t_triangle *)object->ptr, ray, t));
	else if (object->type == CYLINDER)
		return (intersect_cylindr(*(t_cylindr *)object->ptr, ray, t));
	return (0);
}

int				intersect_with_object(t_list *objects, t_ray ray,
				t_object **closest, double *t_min)
{
	double		t;
	t_list		*list;

	list = objects;
	*closest = NULL;
	*t_min = FAR;
	while (list)
	{
		if (intersect(ray, list->content, &t))
		{
			if (t < *t_min)
			{
				*closest = list->content;
				*t_min = t;
			}
		}
		list = list->next;
	}
	return ((*closest) ? 1 : 0);
}
