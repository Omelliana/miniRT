/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:05:09 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/17 01:00:52 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect		new_inter(t_axis impact_point, t_axis impact_normal,
				t_object *closest)
{
	t_intersect inter;

	inter.impact_point = impact_point;
	inter.impact_normal = impact_normal;
	inter.closest = closest;
	return (inter);
}
