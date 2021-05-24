/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_ilist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:46:11 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/21 14:49:10 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*ft_int_lstnew(int nb)
{
	t_ilist	*head;

	head = (t_ilist*)malloc(sizeof(t_ilist));
	if (head == 0)
		return (NULL);
	head->nb = nb;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	ft_int_lstadd_next(t_ilist **alst, t_ilist *l_new)
{
	if (alst && *alst && l_new)
	{
		if ((*alst)->next != NULL)
		{
			l_new->prev = (*alst)->prev;
			l_new->next = (*alst);
			(*alst)->prev->next = l_new;
			(*alst)->prev = l_new;
		}
		else
		{
			(*alst)->next = l_new;
			(*alst)->prev = l_new;
			l_new->next = (*alst);
			l_new->prev = (*alst);
		}
	}
	else if (l_new)
		*alst = l_new;
}

void	ft_int_lstadd_prev(t_ilist **alst, t_ilist *l_new)
{

	if (alst && *alst && l_new)
	{
		if ((*alst)->next != NULL)
		{
			l_new->prev = (*alst);
			l_new->next = (*alst)->next;
			(*alst)->next->prev = l_new;
			(*alst)->next = l_new;
		}
		else
		{
			(*alst)->next = l_new;
			(*alst)->prev = l_new;
			l_new->next = (*alst);
			l_new->prev = (*alst);
		}
	}
	else if (l_new)
		*alst = l_new;
}
