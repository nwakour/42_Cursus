/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:24:13 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/17 15:23:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
