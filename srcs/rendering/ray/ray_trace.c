/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:03:07 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 16:03:35 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_frgb			black_and_white(t_frgb color)
{
	float		black;
	t_frgb		result;

	black = color.r * 0.333 + color.g * 0.333 + color.b * 0.333;
	result.r = black;
	result.g = black;
	result.b = black;
	return (result);
}

int				ray_tracing(t_scene *scene, t_ray ray)
{
	double		t_min;
	t_object	*closest;
	t_frgb		result;
	t_frgb		ambient_color;
	t_frgb		shade_color;

	if (intersect_with_object(scene->obj_list, ray, &closest, &t_min))
	{
		ambient_color = color_coefficient(scene->amb.rgb,
										scene->amb.ratio);
		shade_color = shade(scene, closest, ray, t_min);
		result = color_summ(color_multiply(closest->color,
							ambient_color), shade_color);
		if (scene->filter)
			result = black_and_white(result);
		return (frgb_to_int(result));
	}
	else
		return (0);
}
