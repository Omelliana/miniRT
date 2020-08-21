/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:42:23 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 02:42:16 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			intersect_plane(t_plane plane, t_ray ray, double *t)
{
	double	denominator;

	denominator = vector_dot(plane.vector, ray.direct);
	if (fabs(denominator) > EPSILA)
	{
		*t = vector_dot(vector_difference(plane.coord, ray.start),
		plane.vector) / denominator;
		return (*t >= 0);
	}
	return (0);
}
