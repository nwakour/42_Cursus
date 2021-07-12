/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:34:29 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:53:04 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_struct_list(t_list **list, void **param, size_t size)
{
	t_list	*new;

	*param = malloc(size);
	if (!*param)
		return (0);
	ft_struct_bezero((void *)*param, size);
	if (*list == NULL)
	{
		*list = ft_lstnew(*param);
		if (!*list)
			return (0);
	}
	else
	{
		new = ft_lstnew(*param);
		if (!new)
			return (0);
		ft_lstadd_back(list, new);
	}
	return (1);
}
