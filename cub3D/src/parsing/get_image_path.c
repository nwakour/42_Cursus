/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:40 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/31 16:52:13 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			check_file_ext(char *line, char *ext)
{
	int		end;

	end = (int)ft_strlen(line) - 1;
	while (end && ft_isspace(line[end]))
		line[end--] = '\0';
	end -= 3;
	if (end >= 4)
	{
		if (ft_strcmp(line + end, ext))
		{
			if (ext[1] == 'x')
				ft_putstr_fd("Error\nTexture must be .xpm\n", 1);
			else if (ext[1] == 'c')
				ft_putstr_fd("Error\nTexture must be .cub\n", 1);
			return (ERROR);
		}
	}
	else
	{
		ft_putstr_fd("Error\nWrong file name\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

int			path(char **dest, char *line, char *cmp, int n)
{
	if (ft_memcmp(line, cmp, n))
		return (ERROR);
	line += 2;
	line += skip_space(line);
	if (check_file_ext(line, ".xpm") == ERROR)
		return (ERROR);
	dest[0] = ft_strdup(line);
	return (SUCCESS);
}
