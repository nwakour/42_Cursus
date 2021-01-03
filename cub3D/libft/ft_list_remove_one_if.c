/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_one_if.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:20:59 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/03 16:15:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	remove_front(t_list **list, void (*free_fct)(void *))
{
	t_list	*prev;

	prev = *list;
	*list = prev->next;
	(*free_fct)(prev->content);
	prev->content = 0;
	free(prev);
	prev = 0;
}

void		ft_list_remove_one_if(t_list **list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (!list || !*list)
		return ;
	if (!(*cmp)((*list)->content, data_ref))
	{
		remove_front(list, free_fct);
		return ;
	}
	prev = *list;
	next = (*list)->next;
	while (prev)
	{
		if (next && !(*cmp)(next->content, data_ref))
		{
			prev->next = next->next;
			(*free_fct)(next->content);
			free(next);
			next = prev->next;
			return ;
		}
		prev = prev->next;
		next = (next) ? next->next : next;
	}
}
