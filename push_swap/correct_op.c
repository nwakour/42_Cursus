/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:46:41 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/16 17:17:13 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void op_s(int *stack, int start , int end)
{
	if (end - start <= 1)
		return ;
	else
		swap(stack, start);
}

static void op_p(int *a, int *b, int *a_start, int *b_start, int len_b)
{
	if (len_b == 0)
		return ;
	else
		push(a, b, a_start, b_start);
}

static void op_r(int *stack, int *start, int *end)
{
	if ((*end) - (*start) <= 1)
		return ;
	else
		rotate(stack, start, end);
}

static void op_rr(int *stack, int *start, int *end)
{
	if ((*end) - (*start) <= 1)
		return ;
	else
		rev_rotate(stack, start, end);
}

void corr_op(int *a, int *b, t_index *index, char *opp)
{
	if (!opp || opp[0] == '\0' || opp[1] == '\0')
		return;
	else if (opp[0] == 's')
	{
		if (opp[1] == 'a' && opp[2] == '\0')
			op_s(a, index->a_start, index->a_end);
		else if (opp[1] == 'b' && opp[2] == '\0')
			op_s(b, index->b_start, index->b_end);
		else if (opp[1] == 's' && opp[2] == '\0')
		{
			op_s(a, index->a_start, index->a_end);
			op_s(b, index->b_start, index->b_end);
		}
	}
	else if (opp[0] == 'p')
	{
		if (opp[1] == 'a' && opp[2] == '\0')
			op_p(a, b, &index->a_start, &index->b_start, index->b_end - index->b_start);
		else if (opp[1] == 'b' && opp[2] == '\0')
			op_p(b, a, &index->b_start, &index->a_start, index->a_end - index->a_start);
	}
	else if (opp[0] == 'r' && opp[2] == '\0')
	{
		if (opp[1] == 'a')
			op_r(a, &index->a_start, &index->a_end);
		else if (opp[1] == 'b')
			op_r(b, &index->b_start, &index->b_end);
		else if (opp[1] == 'r')
		{
			op_r(a, &index->a_start, &index->a_end);
			op_r(b, &index->b_start, &index->b_end);
		}
	}
	else if (opp[0] == 'r' && opp[1] == 'r')
	{
		if (opp[2] == 'a' && opp[3] == '\0')
			op_rr(a, &index->a_start, &index->a_end);
		else if (opp[2] == 'b' && opp[3] == '\0')
			op_rr(b, &index->b_start, &index->b_end);
		else if (opp[2] == 'r' && opp[3] == '\0')
		{
			op_rr(a, &index->a_start, &index->a_end);
			op_rr(b, &index->b_start, &index->b_end);
		}
	}
	else
		printf("---nothing\n");
}
