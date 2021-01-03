/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:21 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/03 16:11:56 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	put_map_in_array(t_all *all,
			int nb_line, int nb_column)
{
	int		i;
	int		j;
	int		len;
	char	*s;
	t_list	*tmp;

	all->map = ft_array_char(nb_line, nb_column);
	tmp = all->info.list;
	if (!all->map)
	{
		ft_putstr_fd("Error\nAllocation failed\n", 1);
		return (ERROR);
	}
	i = -1;
	while (++i < nb_line)
	{
		j = -1;
		s = tmp->content;
		if (s[0] == '\0')
		{
			ft_putstr_fd("Error\nempty line in the middle of the map\n", 1);
			return (ERROR);
		}
		len = ft_strlen(s);
		while (++j < len)
			all->map[i][j] = s[j];
		tmp = tmp->next;
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
	else if ((all->info.color_floor == -1) &&
			!get_color(&all->info.color_floor, line, "F "))
		return (SUCCESS);
	else if ((all->info.color_ceil == -1) &&
			!get_color(&all->info.color_ceil, line, "C "))
		return (SUCCESS);
	else
	{
		ft_putstr_fd("Error\nWrong identifier\n", 1);
		return (free_all(all, ERROR));
	}
}

static int	get_map(t_list **list, int fd, char *line, int end)
{
	t_list	*new;
	int		found;

	end = 1;
	found = 0;
	while (end)
	{
		if ((end = get_next_line(fd, &line)) == ERROR)
		{
			ft_putstr_fd("Error\nReading file failed\n", 1);
			return (ERROR);
		}
		if (line[0] != '\0' && !found)
			found = 1;
		if (found)
		{
			if (!(new = ft_lstnew(line)))
			{
				ft_putstr_fd("Error\nAllocation failed\n", 1);
				return (ERROR);
			}
			ft_lstadd_back(list, new);
		}
	}
	if (close(fd) != SUCCESS)
	{
		ft_putstr_fd("Error\nClosing file failed\n", 1);
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
			ft_putstr_fd("Error\nReading file failed\n", 1);
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
	if ((put_map_in_array(all,
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
