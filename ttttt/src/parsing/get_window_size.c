/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:44 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/11 17:34:54 by nwakour          ###   ########.fr       */
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
		perror("Error\nCorrect resolution format is 'R Width Height'\n");
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
		perror("Error\nCorrect resolution format is 'R Width Height'\n");
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
		perror("Error\nCorrect resolution format is 'R Width Height'\n");
		return (0);
	}
	line += skip_space(line);
	if (*line)
	{
		perror("Error\nCorrect resolution format is 'R Width Height'\n");
		return (0);
	}
	*window_height = size_height;
	return (line);
}

int		get_window_size(t_all *all)
{
	char	*line;
	t_list	*node;

	if (!(node = get_node(&all->info.list, "R ", 2)))
	{
		perror("Error\nCorrect resolution format is 'R Width Height'\n");
		return (ERROR);
	}
	line = node->content;
	if (!(line = get_width(line, &all->info.window_width)))
		return (ERROR);
	if (!(line = get_height(line, &all->info.window_height)))
		return (ERROR);
	if (all->info.window_width < 100 || all->info.window_height < 100)
	{
		perror("Error\nWidth and Height must be greater than 100\n");
		return (ERROR);
	}
	ft_list_remove_one_if(&all->info.list, node->content,
						&ft_strcmp, &free_content_node);
	return (SUCCESS);
}
