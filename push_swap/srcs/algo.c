/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:49:22 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/11 15:48:11 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_stack3(t_ilist **a)
{
	long first;
	long second;
	long third;

	first = (*a)->nb;
	second = (*a)->next->nb;
	third = (*a)->next->next->nb;
	if (first > second && first > third && second > third)
	{
		swap(*a, 'a', 1);
		rev_rotate(a, 'a', 1);
	}
	else if (first > second && first > third && second < third)
		rotate(a, 'a', 1);
	else if (first > second && first < third && second < third)
		swap(*a, 'a', 1);
	else if (first < second && first > third && second > third)
		rev_rotate(a, 'a', 1);
	else if (first < second && first < third && second > third)
	{
		rev_rotate(a, 'a', 1);
		swap(*a, 'a', 1);
	}
}

static void sort_stack5(t_ilist **a, t_ilist **b, int len_a)
{
	while (len_a-- > 3)
		push(b, a, 'b', 1);
	sort_stack3(a);
	// print_t_ilists(*a, *b);
	while (*b)
	{
		if((*a)->nb > (*b)->nb)
		{
			push(a, b, 'a', 1);
			if (*b)
				rev_rotate(a, 'a', 1);
			// print_t_ilists(*a, *b);
		}
		else
		{
			rotate(a, 'a', 1);
			// print_t_ilists(*a, *b);
		}
	}
}

static void radix_sort(t_ilist **a, t_ilist **b, int len_a)
{
	int i;
	int j;
	int nb;

	i = -1;
	while (!is_sorted(*a, *b))
	{
		i++;
		j = -1;
		while (++j < len_a)
		{
			nb = (*a)->nb;
			if(((nb >> i)&1))
				rotate(a, 'a', 1);
			else
				push(b, a, 'b', 1);
		}
		while (*b)
			push(a, b, 'a', 1);
	}
}

void sort_stack(t_ilist **a, t_ilist **b)
{
	int len_a;
	t_ilist *stack_dup;

	len_a = ft_int_lstsize(*a);
	if (len_a == 2)
		swap(*a, 'a', 1);
	else if (len_a == 3)
		sort_stack3(a);
	else if (len_a > 3 && len_a <= 5)
		sort_stack5(a, b, len_a);
	else
	{
		stack_dup = ft_int_lstdup(*a);
		pre_sort(stack_dup);
		index_stack(*a, stack_dup);
		radix_sort(a, b, len_a);
		orgin_stack(*a, stack_dup);
	}
}
