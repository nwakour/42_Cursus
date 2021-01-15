/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:44 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/13 17:53:26 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_width(char *line, int *window_width)
{
	int	size_width;

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
		size_width = atoi(line);
		line += skip_number(line);
	}
	else
	{
		ft_putstr_fd("Error\nresolution format is 'R Width Height'\n", 1);
		return (0);
	}
	*window_width = size_width;
	return (line);
}

char	*get_height(char *line, int *window_height)
{
	int	size_height;

	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		size_height = atoi(line);
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
	*window_height = size_height;
	return (line);
}

int		get_window_size(t_all *all, char *line)
{
	if (all->info.window_width != -1)
	{
		ft_putstr_fd("Error\nDuplicate parametres\n", 1);
		return (ERROR);
	}
	if (!(line = get_width(line, &all->info.window_width)))
		return (ERROR);
	if (!(line = get_height(line, &all->info.window_height)))
		return (ERROR);
	if (all->info.window_width < 100 || all->info.window_height < 100)
	{
		ft_putstr_fd("Error\nWidth and Height must be greater than 100\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}
