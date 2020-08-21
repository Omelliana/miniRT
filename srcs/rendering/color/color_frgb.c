/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_frgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:31:10 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/17 00:29:41 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				frgb_to_int(t_frgb a)
{
	t_rgb		rgb;

	rgb.r = a.r * 255;
	rgb.g = a.g * 255;
	rgb.b = a.b * 255;
	return (color_to_int(rgb));
}

t_frgb			color_multiply(t_frgb a, t_frgb b)
{
	t_frgb		color;

	color.r = fmin(a.r * b.r, 1);
	color.g = fmin(a.g * b.g, 1);
	color.b = fmin(a.b * b.b, 1);
	return (color);
}

t_frgb			color_coefficient(t_frgb f_color, double coeff)
{
	t_frgb		color;

	color.r = fmin(f_color.r * coeff, 1);
	color.g = fmin(f_color.g * coeff, 1);
	color.b = fmin(f_color.b * coeff, 1);
	return (color);
}

t_frgb			color_summ(t_frgb a, t_frgb b)
{
	t_frgb		color;

	color.r = fmin(a.r + b.r, 1);
	color.g = fmin(a.g + b.g, 1);
	color.b = fmin(a.b + b.b, 1);
	return (color);
}
