/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:21 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/16 15:21:38 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	map_in_array(t_all *all)
{
	int		i;
	int		j;
	int		len;
	char	*s;
	t_list	*tmp;

	tmp = all->info.list;
	i = -1;
	while (++i < all->info.rows_nb)
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

static int	get_info(t_all *all, char *line, int *lines)
{
	if (line[0] == 'R' && (get_window_size(all, line) == ERROR))
		return (ERROR);
	if (line[0] == 'N' && (path(&all->tex[NO].path, line, "NO ", 3) == ERROR))
		return (ERROR);
	if (line[0] == 'S' && line[1] == 'O' &&
		(path(&all->tex[SO].path, line, "SO ", 3) == ERROR))
		return (ERROR);
	if (line[0] == 'W' && (path(&all->tex[WE].path, line, "WE ", 3) == ERROR))
		return (ERROR);
	if (line[0] == 'E' && (path(&all->tex[EA].path, line, "EA ", 3) == ERROR))
		return (ERROR);
	if (line[0] == 'S' && line[1] == ' ' &&
		(path(&all->tex[S].path, line, "S ", 2) == ERROR))
		return (ERROR);
	if (line[0] == 'F' &&
		(get_color(&all->info.color_floor, line, "F ") == ERROR))
		return (ERROR);
	if (line[0] == 'C' &&
		(get_color(&all->info.color_ceil, line, "C ") == ERROR))
		return (ERROR);
	ft_lstclear_one_if(&all->info.list, line, ft_strcmp, free_content);
	(*lines)++;
	return (SUCCESS);
}

static int	read_file(t_all *all)
{
	char	*line;
	t_list	*new;
	int		end;

	end = 1;
	while (end)
	{
		if ((end = get_next_line(all->info.fd, &line)) == ERROR)
		{
			ft_putstr_fd("Error\nReading file failed\n", 1);
			return (ERROR);
		}
		if (!(new = ft_lstnew(line)))
		{
			ft_putstr_fd("Error\nAllocation failed\n", 1);
			return (ERROR);
		}
		ft_lstadd_back(&all->info.list, new);
	}
	if (close(all->info.fd) == ERROR)
	{
		ft_putstr_fd("Error\nClosing file failed\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	get_data(t_all *all)
{
	t_list	*tmp;
	char	*line;
	int		lines;

	tmp = all->info.list;
	lines = 0;
	while (tmp && lines < 8 && (line = tmp->content))
	{
		if (line[0] != '\0' && ft_strchr("RNSWEFC", line[0]))
		{
			if (get_info(all, line, &lines) == ERROR)
				return (ERROR);
		}
		else if (line[0] == '\0')
			ft_lstclear_one_if(&all->info.list, line, ft_strcmp, free_content);
		else
		{
			ft_putstr_fd("Error\nWrong or missing identifier\n", 1);
			return (ERROR);
		}
		tmp = all->info.list;
	}
	if (lines < 8 || !tmp)
		return (ERROR);
	return (SUCCESS);
}

int			parsing(t_all *all)
{
	if ((read_file(all)) == ERROR)
		return (free_all(all, ERROR));
	if ((get_data(all)) == ERROR)
		return (free_all(all, ERROR));
	if ((delete_empty_line_map(&all->info.list)) == ERROR)
		return (free_all(all, ERROR));
	if ((rows_cols_nb(all)) == ERROR)
		return (free_all(all, ERROR));
	if ((map_in_array(all)) == ERROR)
		return (free_all(all, ERROR));
	if ((check_that_line_is_wall(all->map[0])) == ERROR)
		return (free_all(all, ERROR));
	if ((check_that_line_is_wall(all->map[all->info.rows_nb - 1])) == ERROR)
		return (free_all(all, ERROR));
	if ((check_map(all, &all->info.orientation)) == ERROR)
		return (free_all(all, ERROR));
	if (all->info.orientation == '\0')
	{
		ft_putstr_fd("Error\nPlayer not found\n", 1);
		return (free_all(all, ERROR));
	}
	return (SUCCESS);
}
