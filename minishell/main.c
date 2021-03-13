/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:40:41 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/11 18:39:38 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	char *line;

	while (1)
	{
		ft_putstr_fd("\033[0;35m minishell-> \033[0m", 1);
		get_next_line(0, &line);
		if (!ft_strcmp(line, "exit"))
		{
			printf("%s\n", line);
			return (0);
		}
		else if (!ft_strncmp(line, "echo", 4))
		{
			printf("%s", line + 4);
			printf("\n");
		}
		else if (!ft_strcmp(line, "ls"))
		{
			printf("\033[0;31m a.out   \033[0;34m libft   \033[0m main.c  \033[0m main.o  \033[0;31m makefile \033[0m");
			printf("\n");
		}
		else
			printf("%s\n", line);
	}
	return (0);
}
