/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:24 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/24 18:03:19 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			rows_cols_nb(t_info *info)
{
	if ((info->rows_nb = ft_lstsize(info->list)) < 3)
	{
		perror("Error\nMore rows are needed\n");
		return (ERROR);
	}
	if ((info->cols_nb = nb_cloumn(info->list)) < 3)
	{
		perror("Error\nMore columns are needed \n");
		return (ERROR);
	}
	return (SUCCESS);
}

int			check_that_line_is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else
		{
			perror("Error\nThe map must be ssurrounded by a wall\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	header_empty_line_map(t_list **begin, t_list *node)
{
	char	*line;
	t_list	*next;

	if (!node)
		return (ERROR);
	line = node->content;
	line += skip_space(line);
	if (!*line)
	{
		next = node->next;
		ft_list_remove_one_if(begin, node->content,
		&ft_strcmp, &free_content_node);
		return (header_empty_line_map(begin, next));
	}
	else if (*line != '1')
		return (ERROR);
	(void)begin;
	return (SUCCESS);
}

static int	footer_empty_line_map(t_list **begin)
{
	char	*line;
	t_list	*node;

	node = ft_lstlast(*begin);
	if (!node)
		return (ERROR);
	line = node->content;
	line += skip_space(line);
	if (!*line || *line != '1')
	{
		return (ERROR);
	}
	(void)begin;
	return (SUCCESS);
}

int			delete_empty_line_map(t_list **begin)
{
	if ((header_empty_line_map(begin, *begin)) == ERROR)
	{
		perror("Error\nWrong map format\n");
		return (ERROR);
	}
	if (footer_empty_line_map(begin) == ERROR)
	{
		perror("Error\nWrong map format");
		return (ERROR);
	}
	(void)begin;
	return (SUCCESS);
}
