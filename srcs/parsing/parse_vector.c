/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:22:01 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 01:26:51 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_axis			parse_axis(char *split, int orientation)
{
	char		**axis;
	t_axis		vector;

	axis = ft_split(split, ',');
	if (ft_sstrlen(axis) != 3)
		error_exit("|Wrong axis count parameter|");
	vector.x = ft_atof(axis[0]);
	vector.y = ft_atof(axis[1]);
	vector.z = ft_atof(axis[2]);
	free_sstr(axis);
	if (((vector.x < -1) || (vector.y < -1) || (vector.z < -1)
	|| (vector.x > 1) || (vector.y > 1) || (vector.z > 1))
	&& orientation)
		error_exit("|Orientation vector range [-1, 1]|");
	if (orientation)
		normal(&vector);
	return (vector);
}

t_frgb			parse_frgb(char *split)
{
	char		**colors;
	t_frgb		rgb;

	colors = ft_split(split, ',');
	if (ft_sstrlen(colors) != 3)
		error_exit("|Wrong rgb count parameter|");
	rgb.r = ft_atoi(colors[0]);
	rgb.g = ft_atoi(colors[1]);
	rgb.b = ft_atoi(colors[2]);
	free_sstr(colors);
	if (((rgb.r < 0) || (rgb.g < 0) || (rgb.b < 0))
	|| ((rgb.r > 255) || (rgb.g > 255) || (rgb.b > 255)))
		error_exit("|Wrong rgb colors range [0-255]|");
	rgb.r /= 256;
	rgb.g /= 256;
	rgb.b /= 256;
	return (rgb);
}
