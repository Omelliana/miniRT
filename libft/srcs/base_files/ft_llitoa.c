/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 23:02:36 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/04 02:44:12 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			ft_get_size_num(long long unsigned num)
{
	unsigned int			size;

	size = 1;
	while (num >= 10)
	{
		size += 1;
		num /= 10;
	}
	return (size);
}

char						*ft_llitoa(long long int n)
{
	unsigned int			size;
	long long unsigned		num;
	char					*res;

	num = (n > 0) ? n : n * (-1);
	size = ft_get_size_num(num);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		size += 1;
	}
	res[size--] = '\0';
	while (num >= 10)
	{
		res[size--] = (num % 10) + '0';
		num /= 10;
	}
	res[size] = (num % 10) + '0';
	return (res);
}
