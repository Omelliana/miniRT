/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:34:50 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/20 20:59:03 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		cicle(t_minirt *mrt)
{
	int			x;
	int			y;
	int			color;

	y = -1;
	while (++y < mrt->scene->res.y)
	{
		x = -1;
		while (++x < mrt->scene->res.x)
		{
			color = ray_tracing(mrt->scene, get_ray(x, y, mrt->scene));
			mrt->image.addr[y * mrt->scene->res.x + x] = color;
		}
	}
}

void			rendering(int camera_number, t_minirt *mrt)
{
	mrt->scene->camera = camera_number;
	cicle(mrt);
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->image.img, 0, 0);
}
