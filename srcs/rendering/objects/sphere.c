/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:08:44 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 13:53:38 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int			get_solution(t_sphere sphere, t_ray ray,
					double *x1, double *x2)
{
	t_params		param;
	t_axis			vec;

	vec = vector_difference(ray.start, sphere.coord);
	param.a = vector_dot(ray.direct, ray.direct);
	param.b = 2.0 * vector_dot(ray.direct, vec);
	param.c = vector_dot(vec, vec) - ft_sqr(sphere.radius);
	return ((solve_equation(param, x1, x2) == 0) ? 0 : 1);
}

int					intersect_sphere(t_sphere sphere, t_ray ray, double *t)
{
	double			x1;
	double			x2;

	if (get_solution(sphere, ray, &x1, &x2) == 0)
		return (0);
	if (x1 < 0)
	{
		x1 = x2;
		if (x1 < 0)
			return (0);
	}
	*t = x1;
	return (1);
}
