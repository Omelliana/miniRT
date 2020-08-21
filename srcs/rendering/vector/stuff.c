/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:45:36 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/16 17:30:36 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			swap_bubble(double *a, double *b)
{
	double		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double			ft_sqr(double n)
{
	return (n * n);
}
