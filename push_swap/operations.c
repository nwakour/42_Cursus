/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/24 21:48:03 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_ilist **stack)
{
	short nb;

	nb = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = nb;
}

void push(t_ilist **a , t_ilist **b)
{
	t_ilist *next;
	t_ilist *prev;

	next = (*b)->next;
	prev = (*b)->prev;
	ft_int_lstadd_next(a, (*b));
	
	(*a) = (*a)->prev;
	if (next != NULL)
	{
		(*b) = next;
		prev->next = (*b);
		(*b)->prev = prev;
	}
	else
		(*b) = NULL;
}
void rotate(t_ilist **stack)
{
	*stack = (*stack)->next;
}

void rev_rotate(t_ilist **stack)
{
	*stack = (*stack)->prev;
}
