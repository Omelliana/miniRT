/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:25:24 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/11 21:23:20 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sstrlen(char **s)
{
	size_t	char_count;

	char_count = 0;
	while (s[char_count])
	{
		char_count += 1;
	}
	return (char_count);
}
