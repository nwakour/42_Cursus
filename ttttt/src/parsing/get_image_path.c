/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:40 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 12:37:50 by nwakour          ###   ########.fr       */
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
				perror("Error\nTexture must be .xpm\n");
			else if (ext[1] == 'c')
				perror("Error\nTexture must be .cub\n");
			return (ERROR);
		}
	}
	else
	{
		perror("Error\nWrong file name\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int			get_image_path(t_list **begin, char *name, int n, char **dest)
{
	t_list	*node;
	char	*line;

	if (!(node = get_node(begin, name, n)))
	{
		perror("Error\nImage error\n");
		return (ERROR);
	}
	line = (char *)node->content;
	line += 2;
	line += skip_space(line);
	if (check_file_ext(line, ".xpm") == ERROR)
		return (ERROR);
	dest[0] = ft_strdup(line);
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &free_content_node);
	(void)dest;
	return (SUCCESS);
}
