/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:34:05 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/17 15:40:01 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char static		*get_width(char *line, int *window_width)
{
	long long	size_width;

	line += skip_space(line);
	if (*line == 'R')
		line++;
	if (!ft_isspace(*line))
	{
		ft_putstr_fd("Error\nresolution format is 'R Width Height'\n", 1);
		return (0);
	}
	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		size_width = ft_atol(line);
		line += skip_number(line);
	}
	else
	{
		ft_putstr_fd("Error\nresolution format is 'R Width Height'\n", 1);
		return (0);
	}
	if (size_width > MAX_VALUE)
		size_width = WINDOW_WIDTH;
	*window_width = size_width;
	return (line);
}

char static		*get_height(char *line, int *window_height)
{
	long long	size_height;

	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		size_height = ft_atol(line);
		line += skip_number(line);
	}
	else
	{
		ft_putstr_fd("Error\nresolution format is 'R Width Height'\n", 1);
		return (0);
	}
	line += skip_space(line);
	if (*line)
	{
		ft_putstr_fd("Error\nresolution format is 'R Width Height'\n", 1);
		return (0);
	}
	if (size_height > MAX_VALUE)
		size_height = WINDOW_HEIGHT;
	*window_height = size_height;
	return (line);
}

int				correct_size(t_all *all)
{
	if (all->info.window_width > WINDOW_WIDTH)
	{
		all->info.real_width = WINDOW_WIDTH;
		all->info.window_width = WINDOW_WIDTH;
	}
	if (all->info.window_height > WINDOW_HEIGHT)
	{
		all->info.real_height = WINDOW_HEIGHT;
		all->info.window_height = WINDOW_HEIGHT;
	}
	all->info.real_height = all->info.window_height;
	all->info.real_width = all->info.window_width;
	if (all->info.real_height < 0 || all->info.real_width < 0)
	{
		ft_putstr_fd("Error\nwrong R value\n", 1);
		return (ERROR);
	}
	if (all->info.window_width < 50)
		all->info.window_width = 100;
	if (all->info.window_height < 100)
		all->info.window_height = 50;
	return (SUCCESS);
}

int				get_window_size(t_all *all, char *line)
{
	if (all->info.window_width != -1 || all->info.window_height != -1)
	{
		ft_putstr_fd("Error\nDuplicate parametres\n", 1);
		return (ERROR);
	}
	if (!(line = get_width(line, &all->info.window_width)))
		return (ERROR);
	if (!(line = get_height(line, &all->info.window_height)))
		return (ERROR);
	if (correct_size(all) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
