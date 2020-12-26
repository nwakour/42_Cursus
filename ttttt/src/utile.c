/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:24:13 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/24 17:52:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		delete_space_in_map(t_all *all, int column)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == ' ')
				all->map[i][j] = '1';
		}
		while (j < column)
			all->map[i][j++] = '1';
	}
}

int			skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (i);
}

int			skip_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

t_list		*get_node(t_list **begin, char *to_find, int n)
{
	t_list	*list;

	list = ft_list_find(*begin, to_find, n, &ft_memcmp);
	if (!list)
		return (0);
	if (list == ft_lstlast(*begin))
		return (0);
	return (list);
}

int			nb_cloumn(t_list *list)
{
	t_list	*tmp;
	int		size;
	int		new_size;

	tmp = list;
	size = 0;
	while (tmp)
	{
		new_size = (int)ft_strlen(tmp->content);
		if (new_size > size)
			size = new_size;
		tmp = tmp->next;
	}
	return (size);
}
