/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:54:41 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:26:53 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;

	dtmp = (unsigned char*)dst;
	stmp = (unsigned char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*dtmp = *stmp;
		dtmp++;
		stmp++;
	}
	return (dst);
}
