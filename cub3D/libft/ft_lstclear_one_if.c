/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_one_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:20:59 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/13 15:36:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear_one_if(t_list **list, void *ref,
		int (*f)(), void (*del)(void*))
{
	t_list	*next;
	t_list	*prev;

	if (!list || !*list || !f || !del)
		return ;
	if (!f((*list)->content, ref) && (prev = *list))
	{
		*list = prev->next;
		ft_lstdelone(prev, del);
		return ;
	}
	prev = *list;
	next = (*list)->next;
	while (prev)
	{
		if (next && !f(next->content, ref) && (prev->next = next->next))
		{
			ft_lstdelone(next, del);
			next = prev->next;
			return ;
		}
		prev = prev->next;
		if (next->next)
			next = next->next;
	}
}
