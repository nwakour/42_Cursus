/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:49:22 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/18 18:21:39 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pivot(int *stack, int start, int end, int len)
{
	int pivot[3];
	int bigger[3];
	int i;

	i = -1;
	srand(time(NULL));
	while (++i < 3)
	{
		pivot[i] = stack[start];
		bigger[i] = 0;
	}
	i = -1;
	while (++i < 3)
	{
		int random = ((rand() % (end - 1 - start + 1)) + start);
		pivot[i] = stack[random];
		if (i == 2 && pivot[0] != pivot[1] && pivot[1] != pivot[2] && pivot[2] != pivot[0])
			break;
		else if (i == 2)
			i = -1;
	}
	while (start < end)
	{
		i = -1;
		while (++i < 3)
		{
			if (stack[start] > pivot[i])
				bigger[i] += 1;
		}
		start++;
	}
	i = -1;
	while (++i < 3)
		bigger[i] = abs(bigger[i] - (len / 2));
	if (bigger[0] <= bigger[1] && bigger[0] <= bigger[2])
		return (pivot[0]);
	else if (bigger[1] <= bigger[0] && bigger[1] <= bigger[2])
		return (pivot[1]);
	else
		return (pivot[2]);
}

void sort_stack(int *a, int *b, t_index *index, int pivot)
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
		if (a[index->a_start] < pivot)
		{
			if ((a[index->a_start] < a[index->a_start + 1] && a[index->a_start + 1] >= pivot)  || (a[index->a_start] > a[index->a_start + 1] && a[index->a_start + 1] < pivot))
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
			if (a[index->a_start + 1] < pivot || a[index->a_start + 1] > a[index->a_start])
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
			else if (a[index->a_start + 1] >= pivot && a[index->a_start] > a[index->a_start + 1])
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
