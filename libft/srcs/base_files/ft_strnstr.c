/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 00:02:13 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/02 01:24:47 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ind_1;
	size_t	ind_2;

	ind_1 = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[ind_1] && (ind_1 < len))
	{
		ind_2 = 0;
		while ((haystack[ind_1 + ind_2] == needle[ind_2])
		&& (needle[ind_2]) && ((ind_1 + ind_2) < len))
			ind_2++;
		if (needle[ind_2] == '\0')
			return ((char *)&haystack[ind_1]);
		ind_1++;
	}
	return (NULL);
}
