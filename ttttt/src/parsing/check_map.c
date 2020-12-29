/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:03 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/29 16:48:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		check_first_character(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line[i] || line[i] != '1')
	{
		perror("Error\nThe map must be surrounded by a Wall\n");
		return (ERROR);
	}
	return (i);
}

static	int		check_last_character(char character)
{
	if (character != '1' && character != ' ')
	{
		perror("Error\nThe map must be surrounded by a Wall\n");
		return (ERROR);
	}
	return (SUCCESS);
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
			{
				perror("Error\nMultiplayer not available for the beta\n");
				return (ERROR);
			}
		}
	}
	else
	{
		perror("Error\nunknown character\n1 = wall\n0 = empty\n2 = sprite\nNSEW = player orientation\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int		check_character_around(char **map, int i, int j)
{
	int	ret;

	ret = 0;
	if (ft_strchr("02NSEW", map[i][j]))
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
	if (ret > 0)
	{
		perror("Error\nMap not closed\n");
		return (ERROR);
	}
	else
		return (SUCCESS);
}

int				check_map(t_all *all, char *orientation)
{
	int			i;
	int			j;
	int			save;

	i = 0;
	save = 0;
	while (all->map[++i])
	{
		if ((j = check_first_character(all->map[i])) == ERROR)
			return (ERROR);
		while (all->map[i][++j])
		{
			if ((is_valide_character(orientation, all->map[i][j])) == ERROR)
				return (ERROR);
			if (check_character_around(all->map, i, j) == ERROR)
				return (ERROR);
			if (all->map[i][j] != ' ')
				save = j;
		}
		if (check_last_character(all->map[i][save]) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
