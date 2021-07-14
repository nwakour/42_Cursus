/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:53:25 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/14 19:45:25 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_space(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isspace(s[i]))
			return (1);
	return (0);
}

static int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

static int	multiple_args(t_ilist **stack, char *arg)
{
	int	skp;

	skp = 0;
	while (arg[skip_space(arg)] != '\0')
	{
		arg += skip_space(arg);
		ft_int_lstadd_back(stack, ft_int_lstnew(ft_atoi_err(arg, &skp)));
		if (skp <= 0 || (skp == 1 && (arg[0] == '-' || arg[0] == '+'))
			|| (!ft_isspace(arg[skp]) && arg[skp] != '\0'))
			return (0);
		arg += skp;
	}
	return (1);
}

int		parse(char **argv, t_ilist	**a)
{
	int		i;
	int		skp;

	i = 0;
	skp = 0;
	while (argv[++i])
	{
		if (has_space(argv[i]))
		{
			if (!multiple_args(a, argv[i]))
				return (0);
		}
		else if (!ft_isstingdigit(argv[i]))
			return (0);
		else
		{
			ft_int_lstadd_back(a, ft_int_lstnew(ft_atoi_err(argv[i], &skp)));
			if (skp <= 0 || (skp == 1
					&& (argv[i][0] == '-' || argv[i][0] == '+')))
				return (0);
		}
	}
	return (1);
}

void	ft_int_lstclear(t_ilist **lst)
{
	t_ilist	*next_node;
	t_ilist	*current;

	if (lst)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			free(current);
		}
		*lst = NULL;
	}
}
