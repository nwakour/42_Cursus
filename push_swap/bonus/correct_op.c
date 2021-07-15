/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:46:41 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/15 12:45:32 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_ilist *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = tmp;
}

void	push(t_ilist **a, t_ilist **b)
{
	t_ilist	*tmp;

	if (!b || !(*b))
		return ;
	tmp = (*b)->next;
	ft_int_lstadd_front(a, (*b));
	(*b) = tmp;
}

void	rotate(t_ilist **stack)
{
	t_ilist	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
}

void	rev_rotate(t_ilist **stack)
{
	t_ilist	*tmp;
	t_ilist	*rot;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	rot = tmp->next;
	rot->next = (*stack);
	tmp->next = NULL;
	(*stack) = rot;
}

int	corr_op(t_ilist **a, t_ilist **b, char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0' || s[1] == '\0')
		return (i);
	if (s[0] == 's' && (s[1] == 'a' || s[1] == 's') && s[2] == '\0' && ++i)
		swap(*a);
	if (s[0] == 's' && (s[1] == 'b' || s[1] == 's') && s[2] == '\0' && ++i)
		swap(*b);
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\0' && ++i)
		push(a, b);
	if (s[0] == 'p' && s[1] == 'b' && s[2] == '\0' && ++i)
		push(b, a);
	if (s[0] == 'r' && (s[1] == 'a' || s[1] == 'r') && s[2] == '\0' && ++i)
		rotate(a);
	if (s[0] == 'r' && (s[1] == 'b' || s[1] == 'r') && s[2] == '\0' && ++i)
		rotate(b);
	if (s[0] == 'r' && s[1] == 'r'
		&& (s[2] == 'a' || s[2] == 'r') && s[3] == '\0' && ++i)
		rev_rotate(a);
	if (s[0] == 'r' && s[1] == 'r'
		&& (s[2] == 'b' || s[2] == 'r') && s[3] == '\0' && ++i)
		rev_rotate(b);
	return (i);
}
