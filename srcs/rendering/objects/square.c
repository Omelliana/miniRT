/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:45:12 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 02:42:09 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			intersect_square(t_square square, t_ray ray, double *t)
{
	double	denominator;
	double	size;
	t_axis	point;

	denominator = vector_dot(square.vector, ray.direct);
	if (fabs(denominator) > EPSILA)
	{
		size = square.size / 2;
		*t = vector_dot(vector_difference(square.coord, ray.start),
		square.vector) / denominator;
		point = vector_difference(vector_summa(ray.start,
		vector_multiply(ray.direct, *t)), square.coord);
		if (*t >= 0)
		{
			return (((fabs(point.x) > size) || (fabs(point.y) > size)
			|| (fabs(point.z) > size)) ? 0 : 1);
		}
	}
	return (0);
}
