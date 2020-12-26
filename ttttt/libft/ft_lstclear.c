/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:48:37 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 16:19:50 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	if (lst && del)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			(*del)(current->content);
			free(current);
		}
		*lst = NULL;
	}
}
