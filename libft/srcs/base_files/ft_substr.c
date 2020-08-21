/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 19:29:46 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:28:45 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	str = NULL;
	if (s)
	{
		if (ft_strlen(s) < start)
			return ((char *)ft_calloc(1, 1));
		len = (ft_strlen(s) - start) > len ? len : ft_strlen(s) - start;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while ((i < len) && (s[start]))
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
