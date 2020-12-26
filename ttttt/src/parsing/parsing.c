/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:21 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 12:53:57 by nwakour          ###   ########.fr       */
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

static	int	put_files_in_list(t_list **begin, int fd)
{
	char	*line;
	t_list	*node;
	int		end;

	end = 1;
	while (end)
	{
		if ((end = get_next_line(fd, &line)) == ERROR)
		{
			perror("Error\nReading file failed\n");
			return (ERROR);
		}
		if (!(node = ft_lstnew(line)))
		{
			perror("Error\nAllocation failed\n");
			return (ERROR);
		}
		ft_lstadd_back(begin, node);
	}
	if (close(fd) != SUCCESS)
	{
		perror("Error\nClosing file failed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	get_info(t_all *all)
{
	if (get_window_size(all) == ERROR)
		return (free_all(all, ERROR));
	if (get_image_path(&all->info.list, "NO ", 3, &all->tex[NO].path) == ERROR)
		return (free_all(all, ERROR));
	if (get_image_path(&all->info.list, "SO ", 3, &all->tex[SO].path) == ERROR)
		return (free_all(all, ERROR));
	if (get_image_path(&all->info.list, "WE ", 3, &all->tex[WE].path) == ERROR)
		return (free_all(all, ERROR));
	if (get_image_path(&all->info.list, "EA ", 3, &all->tex[EA].path) == ERROR)
		return (free_all(all, ERROR));
	if (get_image_path(&all->info.list, "S ", 2, &all->tex[S].path) == ERROR)
		return (free_all(all, ERROR));
	if (get_color(&all->info.list, "C ", &all->info.color_ceiling) == ERROR)
		return (free_all(all, ERROR));
	if (get_color(&all->info.list, "F ", &all->info.color_floor) == ERROR)
		return (free_all(all, ERROR));
	return (SUCCESS);
}

static int	read_map(t_all *all)
{
	if ((delete_empty_line_map(&all->info.list) == ERROR))
		return (free_all(all, ERROR));
	if ((rows_cols_nb(&all->info)) == ERROR)
		return (free_all(all, ERROR));
	if ((put_map_in_array(all, all->info.list,
		all->info.rows_nb, all->info.cols_nb)) == ERROR)
		return (free_all(all, ERROR));
	ft_lstclear(&all->info.list, &free_content_node);
	if (check_that_line_is_wall(all->map[0]) == ERROR)
		return (free_all(all, ERROR));
	if (check_that_line_is_wall(all->map[all->info.rows_nb - 1]) == ERROR)
		return (free_all(all, ERROR));
	if (check_map(all, &all->info.orientation) == ERROR)
		return (free_all(all, ERROR));
	all->info.list = 0;
	return (SUCCESS);
}

int			parsing(t_all *all)
{
	if (put_files_in_list(&all->info.list, all->info.fd) == ERROR)
		return (free_all(all, ERROR));
	if (get_info(all) == ERROR)
		return (ERROR);
	if ((read_map(all)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
