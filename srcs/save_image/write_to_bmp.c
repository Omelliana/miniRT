/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:03:37 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 15:57:40 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void			init_header(unsigned char *header)
{
	ft_memset(header, 0, PIXEL_DATA_OFFSET);
	header[0] = 'B';
	header[1] = 'M';
	header[10] = PIXEL_DATA_OFFSET;
	header[14] = HEADER_SIZE;
	header[26] = PLANES;
	header[28] = BITS_PER_PIXEL;
}

static void			fill_sizes(unsigned char *header, unsigned int height,
					unsigned int width)
{
	unsigned int pixels_in_row;
	unsigned int padding_in_row;

	*(unsigned int *)(&header[18]) = width;
	*(unsigned int *)(&header[22]) = height;
	pixels_in_row = width * sizeof(t_buffer);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	header[2] = PIXEL_DATA_OFFSET + (pixels_in_row + padding_in_row) * height;
}

static void			write_file(unsigned int height, unsigned int width,
					t_buffer **buffer, int fd)
{
	int				row;
	unsigned int	pixels_in_row;
	unsigned int	padding_in_row;
	unsigned char	zeroes[3];

	zeroes[0] = 0;
	zeroes[1] = 0;
	zeroes[2] = 0;
	pixels_in_row = width * sizeof(t_buffer);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	row = height;
	while (row >= 0)
	{
		write(fd, buffer[row], pixels_in_row);
		write(fd, zeroes, padding_in_row);
		row--;
	}
}

void				write_to_bmp(char *filename, unsigned int width,
					unsigned int height, t_buffer **buffer)
{
	int				fd;
	unsigned char	header[PIXEL_DATA_OFFSET];

	init_header(header);
	fill_sizes(header, height, width);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, header, PIXEL_DATA_OFFSET);
	write_file(height, width, buffer, fd);
	close(fd);
}
