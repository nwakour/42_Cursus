/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:12:15 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 15:38:15 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

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
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	send_binary(pid, '\n');
	return (0);
}
