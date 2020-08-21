/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:28:10 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/10 00:24:46 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_get_size_num(long long unsigned int num)
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

char					*ft_lluitoa(long long unsigned int num)
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
