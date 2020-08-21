/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shades.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:17:41 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 23:23:20 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_frgb		get_ligth_impact(t_axis impact_point, t_axis impact_normal,
							t_object *closest, t_scene *scene)
{
	t_list	*list;
	t_frgb	color;
	t_frgb	light;

	color = int_to_frgb(0);
	list = scene->light_list;
	while (list)
	{
		light = light_color(*(t_light *)(list->content),
		new_inter(impact_point, impact_normal, closest), *scene);
		color = color_summ(color, light);
		list = list->next;
	}
	return (color);
}

t_frgb		shade(t_scene *scene, t_object *closest, t_ray ray, double t_min)
{
	t_axis	impact_point;
	t_axis	impact_normal;

	impact_point = vector_summa(ray.start, vector_multiply(ray.direct, t_min));
	impact_normal = get_normal(impact_point, closest);
	if (vector_dot(ray.direct, impact_normal) > 0)
		impact_normal = vector_difference(init_vector(0, 0, 0),
		vector_multiply(impact_normal, 1));
	return (get_ligth_impact(impact_point, impact_normal, closest, scene));
}
