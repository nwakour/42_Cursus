/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 14:56:46 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ilist *stack, char c, int fd)
{
	long	tmp;

	tmp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = tmp;
	if (c == 'a')
		ft_putendl_fd("sa", fd);
	else if (c == 'b')
		ft_putendl_fd("sb", fd);
	else
		ft_putendl_fd("rs", fd);
}

void	push(t_ilist **a, t_ilist **b, char c, int fd)
{
	t_ilist	*tmp;

	tmp = (*b)->next;
	ft_int_lstadd_front(a, (*b));
	(*b) = tmp;
	if (c == 'a')
		ft_putendl_fd("pa", fd);
	else
		ft_putendl_fd("pb", fd);
}

void	rotate(t_ilist **stack, char c, int fd)
{
	t_ilist	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
	if (c == 'a')
		ft_putendl_fd("ra", fd);
	else if (c == 'b')
		ft_putendl_fd("rb", fd);
	else
		ft_putendl_fd("rr", fd);
}

void	rev_rotate(t_ilist **stack, char c, int fd)
{
	t_ilist	*tmp;
	t_ilist	*rot;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	rot = tmp->next;
	rot->next = (*stack);
	tmp->next = NULL;
	(*stack) = rot;
	if (c == 'a')
		ft_putendl_fd("rra", fd);
	else if (c == 'b')
		ft_putendl_fd("rrb", fd);
	else
		ft_putendl_fd("rrr", fd);
}
