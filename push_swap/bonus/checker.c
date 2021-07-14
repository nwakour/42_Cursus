/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:43:48 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/14 18:48:01 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	checker(t_ilist **stack_a, t_ilist **stack_b, char *buff)
{
	char	c;
	int		r;

	while (1)
	{
		r = read(0, &c, 1);
		if (r <= 0 || !buff || (buff[0] == '\0' && c == '\n'))
			break ;
		if (c == '\n')
		{
			if (!corr_op(stack_a, stack_b, buff))
				break ;
			free(buff);
			buff = ft_strdup("");
		}
		else
			buff = ft_strjoin_char(buff, c);
	}
	if (buff)
		free(buff);
	if (r == 0 && buff &&buff[0] == '\0')
		return (1);
	return (0);
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
		if (checker(&stack_a, &stack_b, ft_strdup("")))
		{
			if (is_sorted(stack_a, stack_b))
				ft_putendl_fd("OK", 1);
			else
				ft_putendl_fd("KO", 1);
		}
		else
			ft_putendl_fd("Error", 1);
	}
	ft_int_lstclear(&stack_a);
	ft_int_lstclear(&stack_b);
	system("leaks checker");
	return (0);
}
