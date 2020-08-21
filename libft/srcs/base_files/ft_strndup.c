/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:00:33 by bodysseu          #+#    #+#             */
/*   Updated: 2020/06/26 23:39:31 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s1, size_t n)
{
	char		*dst;
	size_t		src_len;
	size_t		i;

	i = 0;
	src_len = 0;
	while (s1[src_len] && (src_len < n))
		src_len++;
	if (!(dst = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (i < src_len)
	{
		dst[i] = s1[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
