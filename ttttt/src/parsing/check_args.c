/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:58 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 12:37:39 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			check_args(t_all *all, int argc, char **argv)
{
	if (argc == 3)
	{
		if (!ft_strcmp("--save", argv[2]))
		{
			all->info.screenshoot = 1;
			if (check_file_ext(argv[1], ".cub") == ERROR)
				exit(ERROR);
		}
		else
		{
			perror("Error\n--save to save the image\n");
			exit(ERROR);
		}
	}
	else if (argc != 2)
	{
		perror("Error\nWrong argument\n");
		exit(ERROR);
	}
	if (argc == 2)
	{
		if (check_file_ext(argv[1], ".cub") == ERROR)
			exit(ERROR);
	}
}
