/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:01:20 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/03 15:08:18 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list *last;

	last = NULL;
	if (!(lst))
		return (last);
	else
	{
		last = lst;
		while (last->next)
			last = last->next;
		return (last);
	}
}
