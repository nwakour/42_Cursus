/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:29:38 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/07 13:46:14 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int next_is_smaller(short *stack, short start)
// {
// 	if (stack[start] > stack[start + 1])
// 		return (1);
// 	return (0);
// }

// static int last_is_bigger(short *stack, short start, short end)
// {
// 	if (stack[start] > stack[end - 1])
// 		return (1);
// 	return (0);
// }

void sort_this(short *a, short *b, t_index *index, int *nb)
{
	// short a_len;
	// short b_len;
	// short one;
	// short two;

	// a_len = index->a_end - index->a_start;
	// b_len = index->b_end - index->b_start;
	// if ((index->a_end - index->a_start) > 1)
	// 	rotate(a, &index->a_start, &index->a_end);
	if (((index->a_end - index->a_start) > 0 && index->b_end - index->b_start > 0 && ((a[index->a_start] > b[index->b_start]) || (a[index->a_start] < b[(index->b_end) - 1]))))
	{
		if (a[index->a_start] < b[(index->b_end) - 1])
		{
			push(b, a, &index->b_start, &index->a_start);
			rotate(b, &index->b_start, &index->b_end);
			printf("pb rb\n");
			(*nb) += 2;
		}
		else
		{
			push(b, a, &index->b_start, &index->a_start);
			printf("pb\n");
			(*nb)++;
		}
	}
	else if ((index->a_end - index->a_start) > 0 && index->b_end - index->b_start == 0 && a[index->a_start] < a[(index->a_start) + 1])
	{
		push(b, a, &index->b_start, &index->a_start);
		printf("pb\n");
		(*nb)++;
	}
	else if ((index->a_end - index->a_start) > 1 && a[index->a_start] > a[(index->a_start) + 1])
	{
		swap(a, index->a_start);
		printf("sa\n");
		(*nb)++;
	}
	else if (a[index->a_start] > b[index->b_end - 1] && a[index->a_start] < b[index->b_start])
	{
		push(a, b, &index->a_start, &index->b_start);
		swap(a, index->a_start);
		printf("pa sa\n");
		(*nb) += 2;
	}
	else
	{
		
		// printf("pa sa\n");
		// int i = 0;
		// while ((index->b_end - index->b_start) != 0)
		// {
		// 	printf("pa\n");
		// 	push(a, b, &index->a_start, &index->b_start);
		// 	i = 0;
		// }
		// while ((index->a_end - index->a_start)  && a[index->a_start] < a[(index->a_start) + 1])
		// {
		// 	rotate(a, &index->a_start, &index->a_end);
		// 	i = 0;
		// // }
		// if ( i == 0)
		// {
		// 	// printf("%d\n",index->b_end - index->b_start);
		print_t_ilists(a, b, index->a_start, index->b_start, index->a_end, index->b_end);
		printf("%d\n", (*nb));
		exit(1);
		
		// }
	}
	// if (b_len < 2)d
	// {
	// 	push(b, a, &index->b_start, &index->a_start);
	// 	printf("pb\n");
	// }
	// else if ((one = next_is_smaller(a, index->a_start)) || (two = next_is_smaller(b, index->b_start)))
	// {
	// 	if (one && two)
	// 	{
	// 		swap(a, index->a_start);
	// 		swap(b, index->b_start);
	// 		printf("ss\n");
	// 	}
	// 	else if (one)
	// 	{
	// 		swap(a, index->a_start);
	// 		printf("sa\n");
	// 	}
	// 	else if (two)
	// 	{
	// 		swap(b, index->b_start);
	// 		printf("sb\n");
	// 	}
	// }
	// else if ((one = last_is_bigger(a, index->a_start, index->a_end)) || (two = last_is_bigger(b, index->b_start, index->b_end)))
	// {
	// 	if (one && two)
	// 	{
	// 		rev_rotate(a, &index->a_start, &index->a_end);
	// 		rev_rotate(b, &index->b_start, &index->b_end);
	// 		printf("rrr\n");
	// 		swap(a, index->a_start);
	// 		swap(b, index->b_start);
	// 		printf("ss\n");
	// 	}
	// 	else if (one)
	// 	{
	// 		rev_rotate(a, &index->a_start, &index->a_end);
	// 		printf("rra\n");
	// 		swap(a, index->a_start);
	// 		printf("sa\n");
	// 	}
	// 	else if (two)
	// 	{
	// 		rev_rotate(b, &index->b_start, &index->b_end);
	// 		printf("rrb\n");
	// 		swap(b, index->b_start);
	// 		printf("sb\n");
	// 	}
	// }
	// // else if (!(one = last_is_bigger(a, index->a_start, index->a_end)) || !(two = last_is_bigger(b, index->b_start, index->b_end)))
	// // {
	// // 	if (!one && !two)
	// // 	{
	// // 		rotate(a, &index->a_start, &index->a_end);
	// // 		rotate(b, &index->b_start, &index->b_end);
	// // 		printf("rr\n");
	// // 		swap(a, index->a_start);
	// // 		swap(b, index->b_start);
	// // 		printf("ss\n");
	// // 	}
	// // 	else if (!one)
	// // 	{
	// // 		rotate(a, &index->a_start, &index->a_end);
	// // 		printf("ra\n");
	// // 		swap(a, index->a_start);
	// // 		printf("sa\n");
	// // 	}
	// // 	else if (!two)
	// // 	{
	// // 		rotate(b, &index->b_start, &index->b_end);
	// // 		printf("rb\n");
	// // 		swap(b, index->b_start);
	// // 		printf("sb\n");
	// // 	}
	// // }
	// else
	// {
	// 	push(a, b, &index->a_start, &index->b_start);
	// 	printf("pa\n");
	// }
}
