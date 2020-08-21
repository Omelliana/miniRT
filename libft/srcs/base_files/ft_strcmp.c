/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 05:29:19 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/11 05:30:22 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if ((str1 == 0) && (str2 == 0))
		return (0);
	while (((str1[index] != '\0') && (str1[index] != '\0')))
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index += 1;
	}
	if ((((str1[index] != '\0') && (str2[index] == '\0'))
	|| ((str1[index] == '\0') && (str2[index] != '\0'))))
		return (str1[index] - str2[index]);
	return (0);
}
