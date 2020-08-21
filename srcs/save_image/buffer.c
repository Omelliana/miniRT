/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:26:06 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/20 21:13:36 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_buffer		get_pixels(int color)
{
	t_rgb		rgb;
	t_buffer	result_color;

	rgb = int_to_rgb(color);
	result_color.r = rgb.r;
	result_color.g = rgb.g;
	result_color.b = rgb.b;
	return (result_color);
}

t_buffer		**create_buff(int x, int y)
{
	int			ind;
	t_buffer	**buff;

	ind = 0;
	if (!(buff = (t_buffer **)malloc(sizeof(t_buffer *) * y)))
		error_exit("|Buffer malloc error|");
	while (ind < y)
		if (!(buff[ind++] = (t_buffer *)malloc(sizeof(t_buffer) * x)))
			error_exit("|Buffer malloc error|");
	return (buff);
}

void			free_buff(t_buffer **buff, int y)
{
	int			ind;

	ind = -1;
	while ((++ind) < y)
		free(buff[ind]);
	free(buff);
}
