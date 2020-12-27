/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:33 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/27 15:42:43 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	char	*get_value_color2(char *line, int column)
{
	line += skip_number(line);
	line += skip_space(line);
	if (column < 2 && *line == ',')
		line += 1;
	else
	{
		line += skip_space(line);
		if (*line)
		{
			perror("Error\nColor error\n");
			return (0);
		}
	}
	return (line);
}

static char		*get_value_color(int *ptr, char *line, int column)
{
	if (!*line)
	{
		perror("Error\nColor format is\nF R,G,B\n");
		return (0);
	}
	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		*ptr = atoi(line);
		if ((*ptr & 255) != *ptr)
		{
			perror("Error\nRGB has less than 256 value\n");
			return (0);
		}
	}
	else
	{
		perror("Error\nColor format is\nF R,G,B\n");
		return (0);
	}
	return ((line = get_value_color2(line, column)));
}

int				get_color(int *num_color, char *line, char *cmp)
{
	int			color[3];

	if (ft_memcmp(line, cmp, 2))
		return (ERROR);
	line += 2;
	if (!(line = get_value_color(&color[0], line, 0)))
		return (ERROR);
	if (!(line = get_value_color(&color[1], line, 1)))
		return (ERROR);
	if (!(line = get_value_color(&color[2], line, 2)))
		return (ERROR);
	*num_color = (((color[0]) << 16) + ((color[1]) << 8) + (color[2]));
	return (SUCCESS);
}
