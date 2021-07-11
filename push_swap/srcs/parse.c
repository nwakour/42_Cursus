/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:53:25 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/11 18:57:05 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		ft_atoi_err(const char *str, int *len)
{
	long long	i;
	long long	sum;
	int			sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		sum = (sum * 10) + str[i] - '0';
		i++;
	}
	if (sum > INT_MAX || sum < INT_MIN)
	{
		*len = -1;
		return (0);
	}
	*len = i;
	return (sign * sum);
}

int has_space(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (ft_isspace(s[i]))
			return (1);
	return (0);
}

int skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

t_ilist		*parse(char **argv)
{
	int i;
	t_ilist *stack;
	int skp;

	stack = NULL;
	i = 0;
	skp = 0;
	while (argv[++i])
	{
		if (has_space(argv[i]))
		{
			while (argv[i][skip_space(argv[i])] != '\0')
			{
				argv[i] += skip_space(argv[i]);
				ft_int_lstadd_back(&stack, ft_int_lstnew(ft_atoi_err(argv[i], &skp)));
				if (skp <= 0 || (skp == 1 && (argv[i][0] == '-' || argv[i][0] == '+'))
					|| (!ft_isspace(argv[i][skp]) && argv[i][skp] != '\0'))
					return (NULL);
				argv[i] += skp;
			}
		}
		else if (!ft_isstingdigit(argv[i]))
			return (NULL);
		else
		{
			ft_int_lstadd_back(&stack, ft_int_lstnew(ft_atoi_err(argv[i], &skp)));
			if (skp <= 0 || (skp == 1 && (argv[i][0] == '-' || argv[i][0] == '+')))
				return (NULL);
		}
	}
	return (stack);
}