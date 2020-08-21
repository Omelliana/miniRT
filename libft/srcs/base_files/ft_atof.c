/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:26:06 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/11 23:37:54 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(char *str)
{
	double	div;
	double	razr;
	int		res;
	int		sign;

	div = 0;
	razr = 1.0;
	res = ft_atoi(str);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : NULL;
	while (ft_isdigit(*str))
		str++;
	if (*str++ == '.')
	{
		while (*str && ft_isdigit(*str))
		{
			razr *= 0.1;
			div += sign * razr * (*str++ - '0');
		}
	}
	return (res + div);
}
