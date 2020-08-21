/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:42:15 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/20 00:48:58 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				intersect_triangle(t_triangle triangle, t_ray ray, double *t)
{
	t_params	param;
	t_axis		v0v1;
	t_axis		v0v2;
	t_axis		tvec;
	t_axis		pvec;

	v0v1 = vector_difference(triangle.second, triangle.first);
	v0v2 = vector_difference(triangle.third, triangle.first);
	pvec = perpendicul_vec(ray.direct, v0v2);
	param.determ = vector_dot(v0v1, pvec);
	if (fabs(param.determ) < EPSILA)
		return (0);
	param.c = 1 / param.determ;
	tvec = vector_difference(ray.start, triangle.first);
	param.a = vector_dot(tvec, pvec) * param.c;
	if (param.a < 0 || param.a > 1)
		return (0);
	tvec = perpendicul_vec(tvec, v0v1);
	param.b = vector_dot(ray.direct, tvec) * param.c;
	if ((param.b < 0) || (param.a + param.b > 1))
		return (0);
	*t = vector_dot(tvec, v0v2) * param.c;
	return (*t >= 0);
}
