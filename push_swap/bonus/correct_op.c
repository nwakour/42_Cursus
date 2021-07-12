/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:46:41 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 17:11:41 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_ilist *stack)
{
	long	tmp;

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

void	corr_op(t_ilist *a, t_ilist *b, char *opp)
{
	if (!opp || opp[0] == '\0' || opp[1] == '\0')
		return ;
	if (opp[0] == 's' && (opp[1] == 'a' || opp[1] == 's') && opp[2] == '\0')
		swap(a);
	if (opp[0] == 's' && (opp[1] == 'b' || opp[1] == 's') && opp[2] == '\0')
		swap(b);
	if (opp[0] == 'p' && opp[1] == 'a' && opp[2] == '\0')
		push(a, b);
	if (opp[0] == 'p' && opp[1] == 'b' && opp[2] == '\0')
		push(b, a);
	if (opp[0] == 'r' && (opp[1] == 'a' || opp[1] == 'r') && opp[2] == '\0')
		rotate(a);
	if (opp[0] == 'r' && (opp[1] == 'b' || opp[1] == 'r') && opp[2] == '\0')
		rotate(b);
	if (opp[0] == 'r' && opp[1] == 'r'
		&& (opp[2] == 'a' || opp[2] == 'r') && opp[3] == '\0')
		rev_rotate(a);
	if (opp[0] == 'r' && opp[1] == 'r'
		&& (opp[2] == 'b' || opp[2] == 'r') && opp[3] == '\0')
		rev_rotate(b);
}
