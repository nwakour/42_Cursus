/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:34:29 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/11 15:40:16 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_struct_list(t_list **list, void **param, size_t size)
{
	t_list *new;

	if (!(*param = malloc(size)))
		return (0);
	ft_struct_bezero((void*)*param, size);
	if (*list == NULL)
	{
		if (!(*list = ft_lstnew(*param)))
			return (0);
	}
	else
	{
		if (!(new = ft_lstnew(*param)))
			return (0);
		ft_lstadd_back(list, new);
	}
	return (1);
}
