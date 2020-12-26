/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:06 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/24 17:47:09 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_character_around(char **map, int i, int j)
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
