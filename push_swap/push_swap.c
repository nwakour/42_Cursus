/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:39 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/20 13:50:06 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(int *a, t_index *index)
{
	int nb;
	int j;
	if ((index->b_end - index->b_start)|| !(index->a_end - index->a_start))
		return (0);
	j = index->a_start;
	nb = a[j];
	while (++j < index->a_end)
	{
		if (nb > a[j])
			return (0);
		else
			nb = a[j];
	}
	return (1);
}

int	check_dup(int *nbs, int size)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i < size)
	{
		tmp = nbs[i];
		j = -1;
		while (++j < size)
		{
			if (tmp == nbs[j] && i != j)
				return (0);
		}
	}
	return (1);
}

int		check_digit(char **nbs)
{
	int i;

	i = 0;
	while (nbs[++i])
	{
		if (!ft_isstingdigit(nbs[i]))
			return (0);
	}
	return (1);
}
int normalize_range(int max, int min, int a)
{
	int range;

	range = max - min;
 	a = (a - min) / range;
	return (range);
}

int		main(int argc, char **argv)
{
	int *nbs;
	int *stack_a;
	int *stack_b;
	char *line;
	int z;
	int j;
	t_index index;

	z = 0;
	if (argc < 2)
		return (0);
	nbs = (int*)malloc(sizeof(int) * (argc - 1));
	while (argv[++z])
		nbs[z - 1] = ft_atoi(argv[z]);
	if (!check_digit(argv) || !check_dup(nbs, argc - 1))
		printf("KO\n");
	else
	{
		printf("OK\n");
		z = -1;
		j = (argc - 1) * 2;
		stack_a = (int*)malloc(sizeof(int)* (argc - 1) * 5);
		stack_b = (int*)malloc(sizeof(int)* (argc - 1) * 5);
		while (++z < argc - 1)
			stack_a[j++] = nbs[z];
		index.a_start = (argc - 1) * 2;
		index.a_end = j;
		index.b_start = j;
		index.b_end = j;
		line = ft_strdup("");
		while (1)
		{
			print_t_ilists(stack_a, stack_b, index.a_start, index.b_start, index.a_end, index.b_end);
			// get_next_line(0, &line);
			// corr_op(stack_a, stack_b, &index, line);
			int pivot = get_pivot(stack_a, index.a_start, index.a_end, index.a_end - index.a_start);
			printf("%d %d\n", pivot, index.a_end - index.a_start);
			sort_stack(stack_a, stack_b, &index, pivot);
			print_t_ilists(stack_a, stack_b, index.a_start, index.b_start, index.a_end, index.b_end);
			
			break;
		}
	}
	return (0);
}
