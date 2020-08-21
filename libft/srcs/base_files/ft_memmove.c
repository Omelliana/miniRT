/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:56:09 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:26:57 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dtmp;
	const char	*stmp;

	dtmp = dst;
	stmp = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (stmp > dtmp)
	{
		while (len--)
		{
			*dtmp++ = *stmp++;
		}
	}
	else
	{
		dtmp += len;
		stmp += len;
		while (len--)
		{
			*--dtmp = *--stmp;
		}
	}
	return (dst);
}
