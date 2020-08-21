/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:19:37 by bodysseu          #+#    #+#             */
/*   Updated: 2020/05/03 17:10:54 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_el;

	if (lst)
	{
		if (!(new_list = ft_lstnew(f(lst->content))))
			return (NULL);
		while (lst->next)
		{
			lst = lst->next;
			if (!(new_el = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_el);
		}
		return (new_list);
	}
	return (NULL);
}
