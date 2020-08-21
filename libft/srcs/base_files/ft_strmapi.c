/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:26:21 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:28:15 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			ind;

	if (!s || !f)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ind = -1;
	while (s[++ind])
	{
		res[ind] = f(ind, s[ind]);
	}
	res[ind] = '\0';
	return (res);
}
