/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:08:10 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/01 17:36:52 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;
	unsigned char	symbol;

	dtmp = (unsigned char*)dst;
	stmp = (unsigned char*)src;
	symbol = (unsigned char)c;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*dtmp = *stmp;
		if (*dtmp == symbol)
		{
			dtmp++;
			return (dtmp);
		}
		dtmp++;
		stmp++;
	}
	return (NULL);
}
