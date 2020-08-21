/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:50:02 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/20 00:49:16 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			check_t(double *t, t_cylindr cylinder, t_ray ray)
{
	t_axis		point;
	t_axis		center;

	center = vector_summa(cylinder.coord,
	vector_multiply(cylinder.vector, cylinder.height));
	point = vector_summa(ray.start, vector_multiply(ray.direct, *t));
	if (vector_dot(cylinder.vector,
	vector_difference(point, cylinder.coord)) <= 0)
		*t = -1;
	if (vector_dot(cylinder.vector, vector_difference(point, center)) >= 0)
		*t = -1;
}

static int		find_root(t_cylindr cylinder, t_ray ray, double *x1, double *x2)
{
	t_axis		a_sqr;
	t_axis		right;
	t_axis		mult;
	t_params	param;

	mult = vector_multiply(cylinder.vector,
	vector_dot(ray.direct, cylinder.vector));
	a_sqr = vector_difference(ray.direct, mult);
	param.a = vector_dot(a_sqr, a_sqr);
	right = vector_difference(vector_difference(ray.start, cylinder.coord),
	vector_multiply(cylinder.vector, vector_dot(vector_difference(ray.start,
	cylinder.coord), cylinder.vector)));
	param.b = 2 * vector_dot(a_sqr, right);
	param.c = vector_dot(right, right) - ft_sqr(cylinder.radius);
	return ((!solve_equation(param, x1, x2)) ? 0 : 1);
}

int				intersect_cylindr(t_cylindr cylinder, t_ray ray, double *t)
{
	double		x1;
	double		x2;

	if (!find_root(cylinder, ray, &x1, &x2))
		return (0);
	(x1 > 0) ? check_t(&x1, cylinder, ray) : NULL;
	(x2 > 0) ? check_t(&x2, cylinder, ray) : NULL;
	if (x1 < 0 && x2 < 0)
		return (0);
	if (x2 < x1)
		*t = (x2 > 0) ? x2 : x1;
	else
		*t = (x1 > 0) ? x1 : x2;
	return (1);
}
