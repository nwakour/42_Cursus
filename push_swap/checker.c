/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:39 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/24 21:24:18 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dup(int *nbs, int size)
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
int		main(int argc, char **argv)
{
	int *nbs;
	int z;
	t_ilist *a;
	t_ilist *b;
	t_ilist *new;
	// char *line;

	a = NULL;
	z = 0;
	b = NULL;
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
		while (++z < argc - 1)
		{
			if (!(new = ft_int_lstnew(nbs[z])))
				return (0);
			ft_int_lstadd_next(&a, new);
		}
		// int tmp = 2147483647;
		// print_t_ilists(a,b,z,0);
		for (int i = 0; i < 1; ++i)
		{
			int d = ai(a, b, z);
			// if (d < tmp)
			// 	tmp = d;
			printf("%d\n", d);
		}
		// printf("%d\n", tmp);
		// system("leaks checker");
		// line = ft_strdup("");
		// while (1)
		// {
		// 	print_t_ilists(a, b);
		// 	get_next_line(0, &line);
		// 	corr_op(&a, &b, line);
		// }
	}
	free(nbs);
	return (0);
}
