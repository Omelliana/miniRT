/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:50:31 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/11 22:22:43 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_what_to_return(int result, int sign, char str)
{
	if (sign == 1)
		return ((result <= -1) && (!ft_isdigit(str)) ? (result * sign) : -1);
	else
		return ((!(ft_isdigit(str)) && result <= -1) ? (result * sign) : 0);
}

int			ft_atoi(const char *str)
{
	int nb_sign;
	int result_atoi;
	int length;

	length = 0;
	result_atoi = 0;
	nb_sign = 1;
	while ((*str) && (ft_isspace(*str)))
		str += 1;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			nb_sign = -1;
		str += 1;
	}
	while ((*str) && (*str >= '0' && *str <= '9'))
	{
		result_atoi = (result_atoi * 10) + (*str++ - '0');
		length += 1;
		if (length == 19)
		{
			return (ft_what_to_return(result_atoi, nb_sign, *str));
		}
	}
	return (result_atoi * nb_sign);
}
