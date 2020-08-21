/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:24:17 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 01:28:19 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_axis		init_vector(double x, double y, double z)
{
	t_axis	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

void		normal(t_axis *vec)
{
	float	len;

	len = sqrt(ft_sqr(vec->x) + ft_sqr(vec->y) + ft_sqr(vec->z));
	if (len != 0)
	{
		vec->x /= len;
		vec->y /= len;
		vec->z /= len;
	}
}

t_axis		perpendicul_vec(t_axis vec_1, t_axis vec_2)
{
	t_axis	vector;

	vector.x = (vec_1.y * vec_2.z) - (vec_1.z * vec_2.y);
	vector.y = (vec_1.z * vec_2.x) - (vec_1.x * vec_2.z);
	vector.z = (vec_1.x * vec_2.y) - (vec_1.y * vec_2.x);
	return (vector);
}

t_axis		vector_difference(t_axis vec1, t_axis vec2)
{
	t_axis	vector;

	vector.x = vec1.x - vec2.x;
	vector.y = vec1.y - vec2.y;
	vector.z = vec1.z - vec2.z;
	return (vector);
}

double		vector_dot(t_axis a, t_axis b)
{
	double	scalar_product;

	scalar_product = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (scalar_product);
}
