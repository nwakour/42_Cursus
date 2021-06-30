/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:54:12 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 16:57:34 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	send_binary(pid_t pid, int c)
{
	int		i;
	int		bin;

	i = 8;
	while (--i >= 0)
	{
		bin = c >> i;
		if (bin & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error\npid not found\n", 1);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error\npid not found\n", 1);
				exit(0);
			}
		}
		usleep(150);
	}
}

void	send_msg(pid_t pid, char *s)
{
	int	i;

	i = -1;
	if (!s | !pid)
		return ;
	while (s[++i])
		send_binary(pid, s[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}
