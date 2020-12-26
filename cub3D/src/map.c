/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:54:12 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 12:57:35 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**list_to_map(t_all *all, t_list **list, int x, int y)
{
	char	**map;
	char	*lcont;
	t_list	*tmp;
	int		i;
	int		j;
	int		len;

	if (all)
		i = -1;
	tmp = *list;
	if (!(map = malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	i = -1;
	all->info.num_sprite = 0;
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
			if (lcont[j] == 'P')
			{
				all->player.x = j * TILE_SIZE;
				all->player.y = i * TILE_SIZE;
				map[i][j] = '0';
			}
			if (lcont[j] == '2')
			{
				init_sprite(all, all->sprite, all->map, 's');
				all->sprite->nb_sprite++;
				map[i][j] = '1';
			}
			j++;
		}
	}
	map[i] = NULL;
	return (map);
}

char	**ft_read_map(t_all *all, int fd)
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
	return (list_to_map(all, &list, map_x, map_y));
}

static int		check_first_character(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i] || line[i] != '1')
		return (-1);
	return (i);
}

static	int		check_last_character(char character)
{
	if (character != '1')
		return (-1);
	return (1);
}

static int		is_valide_character(char *orientation, char character)
{
	char		*ptr;

	ptr = ft_strchr("012NSEW ", character);
	if (ptr)
	{
		if (ft_strchr("NSEW", character))
		{
			if (*orientation == '\0')
				*orientation = character;
			else
				return (-1);
		}
	}
	else
		return (-1);
	return (1);
}

int		check_character_around(char **map, int i, int j)
{
	int	ret;

	ret = 0;
	if (ft_strchr("012NSEW", map[i][j]))
	{
		if (map[i][j] == ' ')
		{
			if (map[i][j + 1] == ' ')
				ret++;
			if (map[i][j - 1] == ' ')
				ret++;
			if (map[i + 1][j] == ' ')
				ret++;
			if (map[i - 1][j] == ' ')
				ret++;
		}
	}
	return (ret == 4 ? -1 : 1);
}

int		ft_check_map(t_all *all, char *orientation)
{
	int			i;
	int			j;
	int			save;

	i = 0;
	save = 0;
	while (all->map[i])
	{
		if ((j = check_first_character(all->map[i])) == -1)
			return (-1);
		while (all->map[i][++j])
		{
			if ((is_valide_character(orientation, all->map[i][j])) == -1)
				return (-1);
			if (check_character_around(all->map, i, j) == -1)
				return (-1);
			if (all->map[i][j] != ' ')
				save = j;
		}
		if (check_last_character(all->map[i][save]) == -1)
			return (-1);
		i++;
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
