/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:36:13 by bodysseu          #+#    #+#             */
/*   Updated: 2020/07/08 18:15:49 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_lluitoa_base(long long unsigned int num,
							const char *base)
{
	char					*res;
	size_t					size;
	long long unsigned int	n;
	size_t					len;

	n = num;
	size = 1;
	len = ft_strlen(base);
	while ((n /= len))
		++size;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	while (size)
	{
		--size;
		res[size] = base[num % len];
		num /= len;
	}
	return (res);
}
