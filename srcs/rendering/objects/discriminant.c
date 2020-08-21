/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:10:41 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/20 18:41:13 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				solve_equation(t_params params, double *x1, double *x2)
{
	params.determ = pow(params.b, 2) - 4 * params.a * params.c;
	if (params.determ < 0)
		return (0);
	*x1 = (-params.b - sqrt(params.determ)) / (params.a * 2);
	*x2 = (-params.b + sqrt(params.determ)) / (params.a * 2);
	(*x1 > *x2) ? swap_bubble(x1, x2) : NULL;
	return (1);
}
