/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:05:55 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:34:44 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_last(t_list **list, void (*del)(void*))
{
	t_list	*last;
	t_list	*prev;
	int		size;

	if (!list || !*list || !del)
		return ;
	if ((*list)->next == NULL)
	{
		ft_lstdelone(*list, del);
		return ;
	}
	size = ft_lstsize(*list) - 1;
	prev = *list;
	while (--size)
		prev = prev->next;
	last = prev->next;
	ft_lstdelone(last, del);
	prev->next = NULL;
}
