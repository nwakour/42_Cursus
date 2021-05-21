/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:39 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/21 19:03:47 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dup(int *nbs, int size)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i <= size)
	{
		tmp = nbs[i];
		j = 0;
		while (nbs[++j])
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
	int i;
	t_ilist *a;
	t_ilist *b;
	t_ilist *new;
	char *line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	nbs = (int*)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (argv[++i])
		nbs[i - 1] = ft_atoi(argv[i]);
	if (!check_digit(argv) || !check_dup(nbs, argc))
		printf("KO\n");
	else
	{
		printf("OK\n");
		i = -1;
		while (++i < argc - 1)
		{
			if (!(new = ft_int_lstnew(nbs[i])))
				return (0);
			ft_int_lstadd_back(&a, new);
		}
		line = ft_strdup("");
		while (1)
		{
			print_t_ilists(a, b);
			get_next_line(0, &line);
			corr_op(&a, &b, line);
		}
	}
	free(nbs);
	return (0);
}
