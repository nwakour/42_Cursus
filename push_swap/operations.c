/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/21 19:07:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_ilist **stack)
{
	t_ilist *tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void push(t_ilist **a , t_ilist **b)
{
	t_ilist *tmp;

	tmp = (*b)->next;
	ft_int_lstadd_front(a, (*b));
	(*b) = tmp;
}

void rotate(t_ilist **stack)
{
	t_ilist *tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}

void rev_rotate(t_ilist **stack)
{
	t_ilist *tmp;
	t_ilist *rot;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	rot = tmp->next;
	rot->next = (*stack);
	tmp->next = NULL;
	(*stack) = rot;
}
