/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:16:27 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/03 17:34:13 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	in_1;
	unsigned int	in_2;

	if (s1 && s2)
	{
		in_1 = ft_strlen(s1) + ft_strlen(s2);
		if (!(new_str = (char *)malloc(sizeof(char) * (1 + in_1))))
			return (NULL);
		in_1 = 0;
		while (s1[in_1])
		{
			new_str[in_1] = s1[in_1];
			in_1++;
		}
		in_2 = 0;
		while (s2[in_2])
		{
			new_str[in_1++] = s2[in_2++];
		}
		new_str[in_1] = '\0';
		return (new_str);
	}
	return (NULL);
}
