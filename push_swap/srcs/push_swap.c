/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:39 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/14 18:33:38 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_ilist *a, t_ilist *b)
{
	long	nb;

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
	t_ilist	*tmp;

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

int	main(int argc, char **argv)
{
	t_ilist	*stack_a;
	t_ilist	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parse(argv, &stack_a) || !check_dup(stack_a))
		ft_putendl_fd("Error", 1);
	else
	{
		if (!is_sorted(stack_a, stack_b))
			sort_stack(&stack_a, &stack_b);
	}
	ft_int_lstclear(&stack_a);
	ft_int_lstclear(&stack_b);
	// system("leaks push_swap");
	return (0);
}
