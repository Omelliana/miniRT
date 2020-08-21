/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:57:24 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:26:26 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*stmp;
	unsigned char	symbol;

	symbol = (unsigned char)c;
	stmp = (unsigned char *)s;
	while (n--)
	{
		if (*stmp == symbol)
		{
			return (stmp);
		}
		stmp += 1;
	}
	return (NULL);
}
