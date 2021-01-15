/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:24 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/13 19:31:45 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			rows_cols_nb(t_all *all)
{
	if ((all->info.rows_nb = ft_lstsize(all->info.list)) < 3)
	{
		ft_putstr_fd("Error\nMore rows are needed\n", 1);
		return (ERROR);
	}
	if ((all->info.cols_nb = nb_cloumn(all->info.list)) < 3)
	{
		ft_putstr_fd("Error\nMore columns are needed \n", 1);
		return (ERROR);
	}
	if (!(all->map = ft_array_char(all->info.rows_nb, all->info.cols_nb)))
	{
		ft_putstr_fd("Error\nAllocation failed\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int			check_that_line_is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else
		{
			ft_putstr_fd("Error\nThe map must be surrounded by a wall\n", 1);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	header_empty_line_map(t_list **list, t_list *node, int found_space)
{
	char	*line;
	t_list	*next;

	if (!node)
		return (ERROR);
	line = node->content;
	if (ft_strlen(line) && !found_space)
		found_space = 1;
	if (!ft_strlen(line) && found_space)
		return (ERROR);
	line += skip_space(line);
	if (!*line)
	{
		next = node->next;
		ft_lstclear_one_if(list, node->content,
		&ft_strcmp, &free_content);
		return (header_empty_line_map(list, next, found_space));
	}
	if (*line != '1')
		return (ERROR);
	return (SUCCESS);
}

static int	footer_empty_line_map(t_list **list, t_list *node)
{
	char	*line;
	t_list	*last;

	last = ft_lstlast(*list);
	if (!node)
		return (ERROR);
	line = last->content;
	if (!ft_strlen(line))
		return (ERROR);
	line += skip_space(line);
	if (!*line)
	{
		ft_lstclear_last(list, &free_content);
		last = ft_lstlast(*list);
		return (footer_empty_line_map(list, last));
	}
	if (*line != '1')
		return (ERROR);
	return (SUCCESS);
}

int			delete_empty_line_map(t_list **list)
{
	if (header_empty_line_map(list, *list, 0) == ERROR)
	{
		ft_putstr_fd("Error\nWrong map format\n", 1);
		return (ERROR);
	}
	if (footer_empty_line_map(list, *list) == ERROR)
	{
		ft_putstr_fd("Error\nWrong map format\n", 1);
		return (ERROR);
	}
	(void)list;
	return (SUCCESS);
}
