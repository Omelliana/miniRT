/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:30:13 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:28:21 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if ((str1 == 0) && (str2 == 0))
		return (0);
	while (((str1[index] != '\0') && (str1[index] != '\0')) && (index < n))
	{
		if (str1[index] != str2[index])
		{
			return (str1[index] - str2[index]);
		}
		index += 1;
	}
	if ((((str1[index] != '\0') && (str2[index] == '\0'))
	|| ((str1[index] == '\0') && (str2[index] != '\0'))) && (index < n))
	{
		return (str1[index] - str2[index]);
	}
	return (0);
}
