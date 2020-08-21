/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:37:27 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/20 21:13:07 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				color_to_int(t_rgb color)
{
	int			result;

	result = 0;
	result |= color.r << 16;
	result |= color.g << 8;
	result |= color.b;
	return (result);
}

t_rgb			int_to_rgb(int color)
{
	t_rgb		result;

	result.b = (color >> 16) & 255;
	result.g = (color >> 8) & 255;
	result.r = color & 255;
	return (result);
}

t_frgb			int_to_frgb(int color)
{
	t_rgb		rgb;
	t_frgb		result;

	rgb = int_to_rgb(color);
	result.r = (float)rgb.r / 255;
	result.g = (float)rgb.g / 255;
	result.b = (float)rgb.b / 255;
	return (result);
}
