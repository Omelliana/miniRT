/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 02:01:52 by bodysseu          #+#    #+#             */
/*   Updated: 2020/06/26 14:20:27 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*array_copy;
	char	*temp;

	if (!(temp = (char*)malloc(sizeof(*array_copy) * (ft_strlen(s1) + 1))))
		return (NULL);
	array_copy = temp;
	while (*s1)
	{
		*array_copy++ = *s1++;
	}
	*array_copy = '\0';
	return (temp);
}
