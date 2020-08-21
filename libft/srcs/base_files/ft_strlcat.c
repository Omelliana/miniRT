/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:36:39 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:28:02 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	first_size;
	size_t	second_size;
	size_t	res_size;

	first_size = 0;
	second_size = 0;
	res_size = 0;
	while (dst[first_size])
		first_size += 1;
	while (src[res_size])
		res_size += 1;
	if (first_size >= dstsize)
		res_size = res_size + dstsize;
	else
		res_size = res_size + first_size;
	while ((src[second_size]) && (first_size + 1 < dstsize))
	{
		dst[first_size] = src[second_size];
		first_size += 1;
		second_size += 1;
	}
	dst[first_size] = '\0';
	return (res_size);
}
