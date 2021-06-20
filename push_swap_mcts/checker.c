/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:39 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/15 15:40:09 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(short *a, t_index *index)
{
	short nb;
	int j;
	// print_t_ilists(a, b);
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

short	check_dup(short *nbs, short size)
{
	short i;
	short j;
	short tmp;

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

short		check_digit(char **nbs)
{
	short i;

	i = 0;
	while (nbs[++i])
	{
		if (!ft_isstingdigit(nbs[i]))
			return (0);
	}
	return (1);
}
int		main(int argc, char **argv)
{
	short *nbs;
	short *stack_a;
	short *stack_b;
	short z;
	short j;
	t_index index;
	// t_ilist *a;
	// t_ilist *b;
	// t_ilist *new;
	// char *line;

	z = 0;
	if (argc < 2)
		return (0);
	nbs = (short*)malloc(sizeof(short) * (argc - 1));
	while (argv[++z])
		nbs[z - 1] = ft_atoi(argv[z]);
	if (!check_digit(argv) || !check_dup(nbs, argc - 1))
		printf("KO\n");
	else
	{
		printf("OK\n");
		z = -1;
		j = (argc - 1) * 2000;
		stack_a = (short*)malloc(sizeof(short)* (argc - 1) * 5000);
		stack_b = (short*)malloc(sizeof(short)* (argc - 1) * 5000);
		while (++z < argc - 1)
		{
			stack_a[j++] = nbs[z];
			// if (!(new = ft_int_lstnew(nbs[z])))
			// 	return (0);
			// ft_int_lstadd_next(&a, new);
		}
		// int tmp = 2147483647;
		// print_t_ilists(a,b,z,0);
		index.a_start = (argc - 1) * 2000;
		index.a_end = j;
		index.b_start = j;
		index.b_end = j;
		// int nb = 0;
		if (!is_sorted(stack_a, &index))
		{
			tree_travesal(stack_a, stack_b, &index);
			print_t_ilists(stack_a, stack_b, index.a_start, index.b_start, index.a_end, index.b_end);
		}
		// int d = ai(stack_a, stack_b, &index);
			// if (d < tmp)
			// 	tmp = d;
		// printf("%d\n", d);
		// printf("%d\n", tmp);
		// system("leaks checker");
		// line = ft_strdup("");
		// while (1)
		// {
		// 	print_t_ilists(a, b);
		// 	get_next_line(0, &line);
		// 	corr_op(&a, &b, line);
	}
	// free(nbs);
	return (0);
}
