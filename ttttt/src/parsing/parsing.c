/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:21 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/27 16:05:28 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	put_map_in_array(t_all *all, t_list *node,
			int nb_line, int nb_column)
{
	int		i;
	int		j;
	int		len;
	char	*s;

	i = -1;
	all->map = array_char(nb_line, nb_column);
	if (!all->map)
	{
		perror("Error\nAllocation failed\n");
		return (ERROR);
	}
	while (++i < nb_line)
	{
		j = -1;
		s = node->content;
		len = ft_strlen(s);
		while (++j < len)
			all->map[i][j] = s[j];
		node = node->next;
	}
	return (SUCCESS);
}

static int	get_info(t_all *all, char *line)
{
	if ((all->info.window_width == -1) && !get_window_size(all, line))
		return (SUCCESS);
	else if (!all->tex[NO].path && !path(&all->tex[NO].path, line, "NO ", 3))
		return (SUCCESS);
	else if (!all->tex[SO].path && !path(&all->tex[SO].path, line, "SO ", 3))
		return (SUCCESS);
	else if (!all->tex[WE].path && !path(&all->tex[WE].path, line, "WE ", 3))
		return (SUCCESS);
	else if (!all->tex[EA].path && !path(&all->tex[EA].path, line, "EA ", 3))
		return (SUCCESS);
	else if (!all->tex[S].path && !path(&all->tex[S].path, line, "S ", 2))
		return (SUCCESS);
	else if ((all->info.color_floor == -1) && !get_color(&all->info.color_floor, line, "F "))
		return (SUCCESS);
	else if ((all->info.color_ceil == -1) && !get_color(&all->info.color_ceil, line, "C "))
		return (SUCCESS);
	else
	{
		perror("Error\nWrong identifier\n");
		return (free_all(all, ERROR));
	}
}

static int	get_map(t_list **list, int fd, char *line, int end)
{
	t_list	*new;

	end = 1;
	while (end)
	{
		if ((end = get_next_line(fd, &line)) == ERROR)
		{
			perror("Error\nReading file failed\n");
			return (ERROR);
		}
		if (!(new = ft_lstnew(line)))
		{
			perror("Error\nAllocation failed\n");
			return (ERROR);
		}
		ft_lstadd_back(list, new);
	}
	if (close(fd) != SUCCESS)
	{
		perror("Error\nClosing file failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	read_file(t_all *all)
{
	char	*line;
	int		end;
	int		lines;

	end = 1;
	lines = 0;
	while (lines != 8 && end)
	{
		if ((end = get_next_line(all->info.fd, &line)) == ERROR)
		{
			perror("Error\nReading file failed\n");
			return (ERROR);
		}
		if (end == 1 && line[0] != '\0')
		{
			if (get_info(all, line) == ERROR)
				return (ERROR);
			else
				lines++;
		}
	}
	if (!end || get_map(&all->info.list, all->info.fd, line, end) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			parsing(t_all *all)
{
	all->info.window_width = -1;
	all->info.color_floor = -1;
	all->info.color_ceil = -1;
	if (read_file(all) == ERROR)
		return (free_all(all, ERROR));
	if ((delete_empty_line_map(&all->info.list) == ERROR))
		return (free_all(all, ERROR));
	if ((rows_cols_nb(&all->info)) == ERROR)
		return (free_all(all, ERROR));
	if ((put_map_in_array(all, all->info.list,
		all->info.rows_nb, all->info.cols_nb)) == ERROR)
		return (free_all(all, ERROR));
	ft_lstclear(&all->info.list, &free_content);
	if (check_that_line_is_wall(all->map[0]) == ERROR)
		return (free_all(all, ERROR));
	if (check_that_line_is_wall(all->map[all->info.rows_nb - 1]) == ERROR)
		return (free_all(all, ERROR));
	if (check_map(all, &all->info.orientation) == ERROR)
		return (free_all(all, ERROR));
	all->info.list = 0;
	return (SUCCESS);
}
