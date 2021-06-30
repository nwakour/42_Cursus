/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:17:46 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 17:02:44 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	if (n < 0)
	{
		unb = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		unb = n;
	if (unb >= 10)
	{
		ft_putnbr_fd(unb / 10, fd);
		ft_putchar_fd(unb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(unb % 10 + '0', fd);
}

int	ft_atoi(const char *str)
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
	sum = sign * sum;
	if (sum > INT_MAX || sum < INT_MIN)
	{
		ft_putstr_fd("Error\nLimit int\n", 1);
		exit (0);
	}
	return (sum);
}
