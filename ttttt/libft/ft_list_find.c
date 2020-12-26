/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:05 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 17:23:32 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref,
		size_t n, int (*cmp)())
{
	while (begin_list)
	{
		if (!(*cmp)(begin_list->content, data_ref, n))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
