/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:10:22 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:28:11 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			size_res;
	size_t			index;

	size_res = 0;
	if (src && dst)
	{
		index = 0;
		while (src[size_res])
		{
			size_res += 1;
		}
		while (src[index] && (index < (dstsize - 1) && (dstsize > 0)))
		{
			dst[index] = src[index];
			index += 1;
		}
		if (dstsize > 0)
			dst[index] = '\0';
	}
	return (size_res);
}
