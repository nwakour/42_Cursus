/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_struct_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:41:18 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/25 15:42:55 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_find_struct_list(t_list *list, size_t i)
{
	t_list	*tmp;

	tmp = list;
	if (tmp == NULL)
		return (NULL);
	while (i--)
	{
		tmp = tmp->next;
		if (tmp == NULL || tmp->content == NULL)
			return (NULL);
	}
	return ((void*)tmp->content);
}
