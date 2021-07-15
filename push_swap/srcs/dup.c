/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:08:12 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/15 12:43:33 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	orgin_stack(t_ilist *a, t_ilist *dup)
{
	while (a)
	{
		a->nb = dup->nb;
		dup = dup->next;
		a = a->next;
	}
}

void	index_stack(t_ilist *stack, t_ilist *dupli)
{
	t_ilist	*tmp;
	int		i;

	while (stack)
	{
		i = 0;
		tmp = dupli;
		while (tmp)
		{
			if (stack->nb == tmp->nb)
			{
				stack->nb = i;
				break ;
			}
			tmp = tmp->next;
			i++;
		}
		stack = stack->next;
	}
}

void	pre_sort(t_ilist *stack)
{
	t_ilist	*tmp;
	int		nb;
	int		len;
	int		i;

	len = ft_int_lstsize(stack);
	i = -1;
	while (++i < len)
	{
		tmp = stack;
		while (tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
			{
				nb = tmp->nb;
				tmp->nb = tmp->next->nb;
				tmp->next->nb = nb;
			}
			tmp = tmp->next;
		}
	}
}

int	find_smallest_or_biggest(t_ilist *stack, int flag)
{
	int		smallest;
	int		biggest;

	smallest = INT_MAX;
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->nb > biggest)
			biggest = stack->nb;
		if (stack->nb < smallest)
			smallest = stack->nb;
		stack = stack->next;
	}
	if (flag == -1)
		return (smallest);
	else
		return (biggest);
}
