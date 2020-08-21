/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:37:16 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/17 14:11:46 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_axis		vector_summa(t_axis vector_1, t_axis vector_2)
{
	t_axis	vector;

	vector.x = vector_1.x + vector_2.x;
	vector.y = vector_1.y + vector_2.y;
	vector.z = vector_1.z + vector_2.z;
	return (vector);
}

t_axis		vector_multiply(t_axis vector, double x)
{
	t_axis	result;

	result.x = vector.x * x;
	result.y = vector.y * x;
	result.z = vector.z * x;
	return (result);
}

double		vector_len(t_axis vector)
{
	return (sqrt(ft_sqr(vector.x) + ft_sqr(vector.y) + ft_sqr(vector.z)));
}
