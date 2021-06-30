/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:49:22 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/30 16:20:55 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_pivot(int *stack, int start, int end, int len, t_pivot *pivot)
{
	int tmp_pivot[3];
	int bigger[3];
	int i;

	i = -1;
	srand(time(NULL));
	while (++i < 3)
	{
		tmp_pivot[i] = stack[start];
		bigger[i] = 0;
	}
	i = -1;
	pivot->limits[0] = INT_MAX;
	pivot->limits[2] = INT_MIN;
	while (++i < 3)
	{
		int random = ((rand() % (end - 1 - start + 1)) + start);
		tmp_pivot[i] = stack[random];
		if (i == 2 && tmp_pivot[0] != tmp_pivot[1] && tmp_pivot[1] != tmp_pivot[2] && tmp_pivot[2] != tmp_pivot[0])
			break;
		else if (i == 2)
			i = -1;
	}
	while (start < end)
	{
		i = -1;
		if (stack[start] < pivot->limits[0])
			pivot->limits[0] = stack[start];
		if (stack[start] > pivot->limits[2])
			pivot->limits[2] = stack[start];
		while (++i < 3)
		{
			if (stack[start] > tmp_pivot[i])
				bigger[i] += 1;
		}
		start++;
	}
	i = -1;
	while (++i < 3)
		bigger[i] = abs(bigger[i] - (len / 2));
	if (bigger[0] <= bigger[1] && bigger[0] <= bigger[2])
		pivot->limits[1] = tmp_pivot[0];
	else if (bigger[1] <= bigger[0] && bigger[1] <= bigger[2])
		pivot->limits[1] = tmp_pivot[1];
	else
		pivot->limits[1] = tmp_pivot[2];
}

void sort_stack100(int *a, int *b, t_index *index, t_pivot *pivot)
{
	int unique;
	int len_a;
	int len_b;
	int last;
	int len;
	int stuck;

	unique = 0;
	last = -1;
	stuck = 0;
	len_a = index->a_end - index->a_start;
	len = index->a_end - index->a_start;
	len_b = index->b_end - index->b_start;
	while (unique < len && !stuck)
	{
		stuck = 1;
		if (a[index->a_start] < pivot->limits[1])
		{
			if ((a[index->a_start] < a[index->a_start + 1] && a[index->a_start + 1] >= pivot->limits[1])  || (a[index->a_start] > a[index->a_start + 1] && a[index->a_start + 1] < pivot->limits[1]))
			{
				if (len_b > 1 && b[index->b_start] < b[index->b_start + 1] && b[index->b_start] > b[index->b_end - 1])
				{
					swap(a, index->a_start);
					swap(b, index->b_start);
					last = SA;
					unique++;
					printf("SS unique = %d %d\n", unique, a[index->a_start]);
					stuck = 0;
				}
				else
				{
					swap(a, index->a_start);
					last = SA;
					unique++;
					printf("SA unique = %d %d\n", unique, a[index->a_start]);
					stuck = 0;
				}
			}
			else
			{
				if (len_b > 1 && b[index->b_start] < b[index->b_end - 1])
				{
					rotate(a, &index->a_start, &index->a_end);
					rotate(b, &index->b_start, &index->b_end);
					if (last != SA)
					{
						unique++;
						printf("a[0] = %d\n", a[index->a_start]);
					}
					printf("RR unique = %d\n", unique);
					last = RA;
					
					stuck = 0;
				}
				else
				{
					rotate(a, &index->a_start, &index->a_end);
					if (last != SA)
					{
						unique++;
						printf("a[0] = %d\n", a[index->a_start]);
					}
					last = RA;
					printf("RA unique = %d\n", unique);
					stuck = 0;
				}
			}
		}
		else
		{
			if (a[index->a_start + 1] < pivot->limits[1] || a[index->a_start + 1] > a[index->a_start])
			{
				push(b, a, &index->b_start, &index->a_start);
				if (last != SA)
				{
					unique++;
					printf("a[0] = %d\n", a[index->a_start]);
				}
				printf("PB unique = %d\n", unique);
				last = PB;
				len_a--;
				len_b++;
				stuck = 0;
			}
			else if (a[index->a_start + 1] >= pivot->limits[1] && a[index->a_start] > a[index->a_start + 1])
			{
				if (len_b > 1 && b[index->b_start] < b[index->b_start + 1] && b[index->b_start] > b[index->b_end - 1])
				{
					swap(a, index->a_start);
					swap(b, index->b_start);
					last = SA;
					printf("SS unique = %d %d\n", unique, a[index->a_start]);
					stuck = 0;
				}
				else
				{
					swap(a, index->a_start);
					last = SA;
					printf("SA unique = %d %d\n", unique, a[index->a_start]);
					stuck = 0;
				}
			}
		}
	}
}

void sort_stack3(int *a, t_index *index)
{
	if (a[index->a_start] > a[index->a_start + 1] && a[index->a_start] > a[index->a_start + 2] && a[index->a_start + 1] > a[index->a_start + 2]) // 3 2 1
	{
		swap(a, index->a_start);
		rev_rotate(a, &index->a_start, &index->a_end);
	}
	else if (a[index->a_start] > a[index->a_start + 1] && a[index->a_start] > a[index->a_start + 2] && a[index->a_start + 1] < a[index->a_start + 2]) // 3 1 2
		rotate(a, &index->a_start, &index->a_end);
	else if (a[index->a_start] > a[index->a_start + 1] && a[index->a_start] < a[index->a_start + 2] && a[index->a_start + 1] < a[index->a_start + 2]) //  2 1 3
		swap(a, index->a_start);
	else if (a[index->a_start] < a[index->a_start + 1] && a[index->a_start] > a[index->a_start + 2] && a[index->a_start + 1] > a[index->a_start + 2]) // 2 3 1
		rev_rotate(a, &index->a_start, &index->a_end);
	else if (a[index->a_start] < a[index->a_start + 1] && a[index->a_start] < a[index->a_start + 2] && a[index->a_start + 1] > a[index->a_start + 2]) // 1 3 2
	{
		rev_rotate(a, &index->a_start, &index->a_end);
		swap(a, index->a_start);
	}
}

int short_stack_value(int *a, t_index *index)
{
	int i;
	int j;
	int stack[9];
	int count;
	int best[2];

	j = 1;
	best[0] = 1;
	i = index->a_start;
	while (i < index->a_end)
		stack[++j] = a[i++];
	stack[1] = a[--i];
	stack[0] = a[--i];
	stack[7] = a[index->a_start];
	stack[8] = a[index->a_start + 1];
	i = -1;
	count = 0;
	while (count < 4 && ++i < 7)
	{
		if (stack[i] > stack[i + 1])
			count = 0;
		count++;
		// if (count > best[0] || (count == best[0] && (i - count) > 1 && (i - count) < 5))
		if (count > best[0])
		{
			best[0] = count;
			best[1] = (i + 1 - count);
		}
	}
	printf("value = %d id = %d %d\n", best[0], best[1], i);
	return (best[1]);
}

void sort_stack5(int *a, int *b, t_index *index)
{
	// push(b, a, &index->b_start, &index->a_start);
	// push(b, a, &index->b_start, &index->a_start);
	// sort_stack3(a, index);
	// if (a[index->a_start] > b[index->b_start] || a[index->a_start] > b[index->b_start + 1])
	// {
	// 	if (a[index->a_start] > b[index->b_start] && a[index->a_start] > b[index->b_start + 1])
	// 	{
	// 		//pa
	// 		//pa
	// 		if (a[index->a_start] > a[index->a_start + 1])
	// 			//sa
	// 	}
	// 	else if (a[index->a_end - 1] < a[index->b_start] || a[index->a_end - 1] < a[index->b_start + 1])
	// 	{
	// 		//pa
	// 		//pa
	// 		if (a[index->a_start] > a[index->a_start + 1])
	// 			//ra
	// 		else
	// 			//sa
	// 			//ra
	// 	}
	// 	else
	// 	{
	// 		if (a[index->b_start] < a[index->b_start + 1])
	// 			//sb
	// 		//pa
	// 		//sa
	// 		//pa
	// 	}
	// }
	(void)b;
	short_stack_value(a, index);
	
}

void sort_stack(int *a, int *b, t_index *index, t_pivot *pivot)
{
	int len_a;

	len_a = index->a_end - index->a_start;
	if (len_a == 3)
		sort_stack3(a, index);
	else if (len_a > 3 && len_a < 100)
		sort_stack5(a, b, index);
	else if (len_a >= 100)
	{
		get_pivot(a, index->a_start, index->a_end, index->a_end - index->a_start, pivot);
		sort_stack100(a, b, index, pivot);
	}
}
