/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:51:52 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/11 20:11:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int is_sorted(t_ilist *a, t_ilist *b)
{
	long nb;

	if (!a || b)
		return (0);
	nb = a->nb;
	while (a->next)
	{
		a = a->next;
		if (nb > a->nb)
			return (0);
		else
			nb = a->nb;
	}
	return (1);
}

int	check_dup(t_ilist *stack)
{
	t_ilist *tmp;

	while (stack)
	{
		tmp = stack;
		while (tmp)
		{
			if (stack->nb == tmp->nb && &tmp->nb != &stack->nb)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_ilist *stack_a;
	t_ilist *stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse(argv);
	// print_t_ilists(stack_a, stack_b);
	if (!stack_a || !check_dup(stack_a))
		ft_putendl_fd("error", 1);
	else
	{
		while (1)
            corr_op(stack_a, stack_b, NULL);
        if (is_sorted(stack_a, stack_b))
            ft_putendl_fd("OK", 1);
        else
            ft_putendl_fd("KO", 1);
	}
	return (0);
}