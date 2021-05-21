/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:46:41 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/21 19:06:47 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void op_s(t_ilist **stack, int len)
{
	if (len <= 1)
		return ;
	else
		swap(stack);
}

static void op_p(t_ilist **a, t_ilist **b, int len_b)
{
	if (len_b == 0)
		return ;
	else
		push(a, b);
}

static void op_r(t_ilist **stack, int len)
{
	if (len <= 1)
		return ;
	else
		rotate(stack);
}

static void op_rr(t_ilist **stack, int len)
{
	if (len <= 1)
		return ;
	else
		rev_rotate(stack);
}

void corr_op(t_ilist **a, t_ilist **b, char *opp)
{
	printf("%s\n", opp);
	if (!opp || opp[0] == '\0' || opp[1] == '\0')
		return;
	else if (opp[0] == 's')
	{
		if (opp[1] == 'a' && opp[2] == '\0')
			op_s(a, ft_int_lstsize(*a));
		else if (opp[1] == 'b' && opp[2] == '\0')
			op_s(b, ft_int_lstsize(*b));
		else if (opp[1] == 's' && opp[2] == '\0')
		{
			op_s(a, ft_int_lstsize(*a));
			op_s(b, ft_int_lstsize(*b));
		}
	}
	else if (opp[0] == 'p')
	{
		if (opp[1] == 'a' && opp[2] == '\0')
			op_p(a, b, ft_int_lstsize(*b));
		else if (opp[1] == 'b' && opp[2] == '\0')
			op_p(b, a, ft_int_lstsize(*a));
	}
	else if (opp[0] == 'r' && opp[2] == '\0')
	{
		if (opp[1] == 'a')
			op_r(a, ft_int_lstsize(*a));
		else if (opp[1] == 'b')
			op_r(b, ft_int_lstsize(*b));
		else if (opp[1] == 'r')
		{
			op_r(a, ft_int_lstsize(*a));
			op_r(b, ft_int_lstsize(*b));
		}
	}
	else if (opp[0] == 'r' && opp[1] == 'r')
	{
		if (opp[2] == 'a' && opp[3] == '\0')
			op_rr(a, ft_int_lstsize(*a));
		else if (opp[2] == 'b' && opp[3] == '\0')
			op_rr(b, ft_int_lstsize(*b));
		else if (opp[2] == 'r' && opp[3] == '\0')
		{
			op_rr(a, ft_int_lstsize(*a));
			op_rr(b, ft_int_lstsize(*b));
		}
	}
	else
		printf("---nothing\n");
}
