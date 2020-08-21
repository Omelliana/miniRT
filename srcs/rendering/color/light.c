/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:44:15 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 02:04:07 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_frgb	get_color(t_light light, t_frgb object_color, double coeff)
{
	t_frgb		result_color;
	t_frgb		light_color;

	light_color = color_coefficient(light.rgb, light.bright);
	result_color = color_coefficient(color_multiply(light_color,
					object_color), coeff);
	return (result_color);
}

t_frgb			light_color(t_light light, t_intersect inters, t_scene scene)
{
	double		t;
	double		coeff;
	t_axis		light_vec;
	t_ray		light_ray;
	t_object	*another_object;

	coeff = 0;
	light_vec = vector_difference(light.coord, inters.impact_point);
	normal(&light_vec);
	light_ray = create_ray(vector_summa(inters.impact_point,
	vector_multiply(inters.impact_normal, 0.1)), light_vec);
	if (!intersect_with_object(scene.obj_list, light_ray,
	&another_object, &t) || t > vector_len(vector_difference(light.coord,
	inters.impact_point)))
		coeff = fmax(0, vector_dot(inters.impact_normal, light_vec));
	return (get_color(light, inters.closest->color, coeff));
}
