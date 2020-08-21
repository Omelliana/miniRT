/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:36:21 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/10 21:06:39 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*new_str;
	unsigned int	ind_1;
	unsigned int	ind_2;

	ind_1 = 0;
	if (!s1)
		return (NULL);
	if (s1[0] == '\0')
	{
		if (!(new_str = (char *)malloc(sizeof(char))))
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	while (s1[ind_1] && ft_is_set(s1[ind_1], set))
		ind_1++;
	ind_2 = ft_strlen(s1) - 1;
	while (ind_2 && ft_is_set(s1[ind_2], set))
		ind_2--;
	new_str = ft_substr(s1, ind_1, ind_2 > ind_1 ? ind_2 - ind_1 + 1 : 0);
	if (!new_str)
		return (NULL);
	return (new_str);
}
