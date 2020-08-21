/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:33:57 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 15:56:52 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		error_exit(char *error_output)
{
	ft_putstr_fd(RED_COLOR "Error\n", 2);
	ft_putstr_fd(error_output, 2);
	ft_putstr_fd("\n" RESET_COLOR, 2);
	exit(EXIT_FAILURE);
}

int			exit_ok(t_minirt *mrt)
{
	free_struct(mrt->scene);
	mlx_clear_window(mrt->mlx, mrt->win);
	mlx_destroy_window(mrt->mlx, mrt->win);
	ft_putstr_fd(BLUE_COLOR "[miniRT closed]\n" RESET_COLOR, 1);
	exit(0);
	return (1);
}
