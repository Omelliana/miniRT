/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:55:17 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/03 16:10:48 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *element;

	if (lst && del)
	{
		while (*lst)
		{
			element = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = element;
		}
		element = NULL;
		lst = NULL;
	}
}
