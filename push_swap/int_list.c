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
	return (head);
}

void	ft_int_lstadd_back(t_ilist **alst, t_ilist *l_new)
{
	t_ilist	*last;

	if (!l_new)
		return ;
	last = *alst;
	l_new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = l_new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = l_new;
	}
}

void	ft_int_lstadd_front(t_ilist **alst, t_ilist *l_new)
{
	if (alst && l_new)
	{
		l_new->next = *alst;
		*alst = l_new;
	}
}

int		ft_int_lstsize(t_ilist *lst)
{
	int		i;
	t_ilist	*element;

	element = lst;
	i = 0;
	while (element)
	{
		i++;
		element = element->next;
	}
	return (i);
}

