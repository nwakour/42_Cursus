/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:49:22 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/15 12:42:14 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack3(t_ilist **a)
{
	int	first;
	int	second;
	int	third;

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

static void	sort_stack5(t_ilist **a, t_ilist **b, int len_a)
{
	int		smallest;
	int		biggest;

	smallest = find_smallest_or_biggest(*a, -1);
	biggest = find_smallest_or_biggest(*a, 1);
	while (len_a > 3)
	{
		if ((*a)->nb == biggest || (*a)->nb == smallest)
		{
			push(b, a, 'b', 1);
			len_a--;
		}
		else
			rotate(a, 'a', 1);
	}
	sort_stack3(a);
	if ((*b)->nb < (*b)->next->nb)
		swap(*b, 'b', 1);
	push(a, b, 'a', 1);
	rotate(a, 'a', 1);
	push(a, b, 'a', 1);
}

static void	sort_stack4(t_ilist **a, t_ilist **b, int len_a)
{
	int		smallest;

	smallest = find_smallest_or_biggest(*a, -1);
	while (len_a > 3)
	{
		if ((*a)->nb == smallest)
		{
			push(b, a, 'b', 1);
			len_a--;
		}
		else
			rotate(a, 'a', 1);
	}
	sort_stack3(a);
	push(a, b, 'a', 1);
}

static void	radix_sort(t_ilist **a, t_ilist **b, int len_a)
{
	int	i;
	int	j;
	int	nb;

	i = -1;
	while (!is_sorted(*a, *b))
	{
		i++;
		j = -1;
		while (++j < len_a)
		{
			nb = (*a)->nb;
			if (((nb >> i) & 1))
				rotate(a, 'a', 1);
			else
				push(b, a, 'b', 1);
		}
		while (*b)
			push(a, b, 'a', 1);
	}
}

void	sort_stack(t_ilist **a, t_ilist **b)
{
	int		len_a;
	t_ilist	*stack_dup;

	len_a = ft_int_lstsize(*a);
	if (len_a == 2)
		swap(*a, 'a', 1);
	else if (len_a == 3)
		sort_stack3(a);
	else if (len_a == 4)
		sort_stack4(a, b, len_a);
	else if (len_a == 5)
		sort_stack5(a, b, len_a);
	else
	{
		stack_dup = ft_int_lstdup(*a);
		pre_sort(stack_dup);
		index_stack(*a, stack_dup);
		radix_sort(a, b, len_a);
		orgin_stack(*a, stack_dup);
		ft_int_lstclear(&stack_dup);
	}
}
