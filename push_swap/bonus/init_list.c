/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:46:42 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/14 14:24:01 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_ilist	*ft_int_lstnew(long nb)
{
	t_ilist	*head;

	head = (t_ilist *)malloc(sizeof(t_ilist));
	if (!head)
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

int	ft_int_lstsize(t_ilist *lst)
{
	long	i;
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

t_ilist	*ft_int_lstdup(t_ilist *list)
{
	t_ilist	*dup;
	long	nb;

	if (!list)
		return (NULL);
	dup = NULL;
	while (list)
	{
		nb = list->nb;
		ft_int_lstadd_back(&dup, ft_int_lstnew(nb));
		list = list->next;
	}
	return (dup);
}
