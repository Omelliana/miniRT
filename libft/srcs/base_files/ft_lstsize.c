/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:53:46 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/03 15:01:13 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*element;

	size = 0;
	if (!(lst))
		return (size);
	else
	{
		element = lst;
		size = 1;
		while (element->next)
		{
			size += 1;
			element = element->next;
		}
	}
	return (size);
}
