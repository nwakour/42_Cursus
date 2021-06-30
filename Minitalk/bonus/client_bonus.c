/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:02:11 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 16:57:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	sighandler(int signum)
{
	static int	c;
	static int	power;

	if (signum == SIGUSR1)
		c += 1 << (7 - power);
	if (++power == 8)
	{
		if (c == 0)
			exit(0);
		write(1, &c, 1);
		c = 0;
		power = 0;
	}
}

static int	error_handle(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("Error\nARGS = PID MSG\n", 1);
		return (0);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
			ft_putstr_fd("Error\nPID = NUM\n", 1);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*tmp;

	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	if (!error_handle(argc, argv))
		return (0);
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	send_binary(pid, '\n');
	send_binary(pid, '\0');
	tmp = ft_itoa(getpid());
	send_msg(pid, tmp);
	free(tmp);
	tmp = NULL;
	send_binary(pid, '\0');
	while (1)
		pause();
	return (0);
}
