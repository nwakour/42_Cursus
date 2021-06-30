/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:54:40 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 17:02:26 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

static int	ft_nblen(long int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nb;
	int			i;

	nb = n;
	i = ft_nblen(nb);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	i = i - 1;
	if (nb == 0)
		str[i] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}
