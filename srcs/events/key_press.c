/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:54:20 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/19 13:30:39 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		get_cam_number(t_minirt *mrt)
{
	int			size;

	size = ft_lstsize(mrt->scene->cam_list);
	if (mrt->camera_number < 0)
		mrt->camera_number = size - 1;
	else if (mrt->camera_number >= size)
		mrt->camera_number = 0;
}

int				key_press(int key, t_minirt *mrt)
{
	if (key == LEFT)
		mrt->camera_number -= 1;
	else if (key == RIGHT)
		mrt->camera_number += 1;
	else if (key == ESC)
		exit_ok(mrt);
	get_cam_number(mrt);
	rendering(mrt->camera_number, mrt);
	return (0);
}
