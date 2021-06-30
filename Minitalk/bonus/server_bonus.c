/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:01:29 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 16:57:31 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sighandler(int signum)
{
	static int	c;
	static int	power;
	static int	pid;
	static int	flag;

	if (signum == SIGUSR1)
		c += 1 << (7 - power);
	if (++power == 8)
	{
		if (c != 0 && !flag)
			write(1, &c, 1);
		else if (c == 0 && flag)
		{
			send_msg(pid, "Message received\n");
			send_binary(pid, '\0');
			flag = 0;
			pid = 0;
		}
		else if (c == 0 && !flag)
			flag = 1;
		else if (c != 0 && flag)
			pid = (pid * 10) + (c - 48);
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
