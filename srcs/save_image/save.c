/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:20:12 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 15:58:00 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			save_to_bmp(t_minirt *mrt)
{
	int				x;
	int				y;
	int				color;
	t_buffer		**buffer;

	y = 0;
	buffer = create_buff(mrt->scene->res.x, mrt->scene->res.y);
	while (y < mrt->scene->res.y)
	{
		x = 0;
		while (x < mrt->scene->res.x)
		{
			color = ray_tracing(mrt->scene, get_ray(x, y, mrt->scene));
			buffer[y][x] = get_pixels(color);
			x++;
		}
		y++;
	}
	write_to_bmp("img.bmp", mrt->scene->res.x, mrt->scene->res.y, buffer);
	free_buff(buffer, mrt->scene->res.y);
}

void				save(char *argv[])
{
	t_minirt		mrt;

	mrt.scene = open_file(argv[1], 1);
	mrt.camera_number = 0;
	save_to_bmp(&mrt);
}
