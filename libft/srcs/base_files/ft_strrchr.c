/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:35:17 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:28:33 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	symbol;

	symbol = (char)c;
	temp = (char *)s + ft_strlen(s);
	while (temp >= s)
	{
		if (*temp == symbol)
		{
			return (temp);
		}
		temp -= 1;
	}
	return (NULL);
}
