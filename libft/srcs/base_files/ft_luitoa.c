/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:26:37 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/04 16:32:48 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_get_size_num(long unsigned int num)
{
	unsigned int		size;

	size = 1;
	while (num >= 10)
	{
		size += 1;
		num /= 10;
	}
	return (size);
}

char					*ft_luitoa(long unsigned int num)
{
	unsigned int		size;
	char				*res;

	size = ft_get_size_num(num);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	while (num >= 10)
	{
		res[size--] = (num % 10) + '0';
		num /= 10;
	}
	res[size] = (num % 10) + '0';
	return (res);
}
