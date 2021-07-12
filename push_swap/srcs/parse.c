/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:53:25 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 16:36:10 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digit(char **nbs)
{
	int	i;

	i = 0;
	while (nbs[++i])
	{
		if (!ft_isstingdigit(nbs[i]))
			return (0);
	}
	return (1);
}

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

static int	multiple_args(t_ilist *stack, char *arg)
{
	int	skp;

	skp = 0;
	while (arg[skip_space(arg)] != '\0')
	{
		arg += skip_space(arg);
		t_int_lstadd_back(&stack, ft_int_lstnew(ft_atoi_err(arg, &skp)));
		if (skp <= 0 || (skp == 1 && (arg[0] == '-' || arg[0] == '+'))
			|| (!ft_isspace(arg[skp]) && arg[skp] != '\0'))
			return (0);
		arg += skp;
	}
	return (1);
}

t_ilist	*parse(char **argv)
{
	int		i;
	int		skp;
	t_ilist	*a;

	a = NULL;
	i = 0;
	skp = 0;
	while (argv[++i])
	{
		if (has_space(argv[i]))
		{
			if (!multiple_args(a, argv[i]))
				return (NULL);
		}
		else if (!ft_isstingdigit(argv[i]))
			return (NULL);
		else
		{
			ft_int_lstadd_back(&a, ft_int_lstnew(ft_atoi_err(argv[i], &skp)));
			if (skp <= 0 || (skp == 1
					&& (argv[i][0] == '-' || argv[i][0] == '+')))
				return (NULL);
		}
	}
	return (a);
}
