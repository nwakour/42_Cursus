/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:26:19 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 15:28:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sighandler(int signum)
{
	static int	c;
	static int	power;

	if (signum == SIGUSR1)
		c += 1 << (7 - power);
	if (++power == 8)
	{
		write(1, &c, 1);
		c = 0;
		power = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	if (argc > 1)
	{
		ft_putstr_fd("Error\nno ARGS needed\n", 1);
		return (0);
	}
	(void)argv;
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
