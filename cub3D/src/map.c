/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:54:12 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/18 11:57:26 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**list_to_map(t_list **list, int x, int y)
{
	char	**map;
	char	*lcont;
	t_list	*tmp;
	int		i;
	int		j;
	int		len;

	tmp = *list;
	if (!(map = malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	i = -1;
	while (++i < x)
	{
		lcont = tmp->content;
		tmp = tmp->next;
		if (!(map[i] = malloc(sizeof(char) * (y + 1))))
			return (NULL);
		j = 0;
		len = ft_strlen(lcont);
		while (j <= y)
		{
			if (j < len)
				map[i][j] = lcont[j];
			else
				map[i][j] = '\0';
			j++;
		}
	}
	map[i] = NULL;
	return (map);
}

char	**ft_read_map(int fd)
{
	t_list	*list;
	char	*line;
	int		i;
	int		map_x;
	int		map_y;
	int		j;

	line = NULL;
	list = NULL;
	map_x = 0;
	map_y = 0;
	i = 1;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '\n')
		{
			if (map_y != 0)
				return (NULL);
			while (line[0] == '\n' && i == 1)
				i = get_next_line(fd, &line);
		}
		if (i == 1)
		{
			j = strlen(line);
			if (j > map_y)
				map_y = j;
			if (line[0] != '\0')
			{
				ft_lstadd_back(&list, ft_lstnew(line));
				map_x++;
			}
			if (j == 0 && map_y > 0)
				return (NULL);
		}
	}
	return (list_to_map(&list, map_x, map_y));
}

int		ft_check_map(char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;

	y = ft_strlen(map[0]);
	while (y > 0)
	{
		if (map[0][--y] == '0')
			return (0);
	}
	x = 1;
	while (map[x + 1] != NULL)
	{
		i = ft_strlen(map[x - 1]);
		j = ft_strlen(map[x]);
		if (i > j)
			i = j;
		while (i < j)
		{
			if (map[x][--j] == '0')
				return (0);
		}
		while (i > 0)
		{
			if (map[x][0] == '0')
				return (0);
			if (map[x][i] == '1')
				i--;
			else if (map[x][i] == ' ')
			{
				if (map[x - 1][i] == '0' || map[x][i - 1] == '0'
					|| map[x][i + 1] == '0' || map[x][i + 1] == '\0')
					return (0);
				i--;
			}
			else if (map[x][i] == '0')
			{
				if (map[x - 1][i] == ' ' || map[x][i - 1] == ' ' ||
					map[x][i + 1] == ' ' || map[x][i + 1] == '\0')
					return (0);
				i--;
			}
			else if (map[x][i] == '\0')
				i--;
		}
		x++;
	}
	i = ft_strlen(map[x]);
	while (i > 0)
	{
		if (map[x][--i] == '0')
			return (0);
	}
	return (1);
}

void	drawmap(t_all *all)
{
	int i;
	int j;
	int len;

	i = 0;
	all->draw.width = TILE_SIZE;
	all->draw.height = TILE_SIZE;
	while (all->map[i] != NULL)
	{
		all->draw.start_y = TILE_SIZE * i;
		len = ft_strlen(all->map[i]);
		j = 0;
		while (j < len)
		{
			all->draw.start_x = TILE_SIZE * j;
			if (all->map[i][j] == '1')
				drawblock(all->mlx.img_data, all->draw, 4079166);
			else if (all->map[i][j] == '0')
				drawblock(all->mlx.img_data, all->draw, 16777215);
			j++;
		}
		i++;
	}
}
