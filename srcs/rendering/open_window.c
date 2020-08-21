/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:54:54 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 13:39:15 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			open_window(char *argv[])
{
	t_minirt	mrt;

	mrt.scene = open_file(argv[1], 0);
	if (!(mrt.mlx = mlx_init()))
		error_exit("|Fails to set up the connection to the  display|");
	if (!(mrt.win = mlx_new_window(mrt.mlx, mrt.scene->res.x,
	mrt.scene->res.y, "miniRT")))
		error_exit("|Fails to create a new window|");
	if (!(mrt.image.img = mlx_new_image(mrt.mlx,
	mrt.scene->res.x, mrt.scene->res.y)))
		error_exit("|Fails to create image|");
	mrt.image.addr = (int *)mlx_get_data_addr(mrt.image.img, &(mrt.image.bits),
	&(mrt.image.line_len), &(mrt.image.endian));
	mlx_hook(mrt.win, 2, 0, key_press, &mrt);
	mlx_hook(mrt.win, 17, 0, exit_ok, &mrt);
	rendering(0, &mrt);
	mlx_loop(mrt.mlx);
}
