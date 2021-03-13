/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:46:01 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/12 17:58:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*content;

	content = lst;
	if (content == NULL)
	{
		return (NULL);
	}
	while (content->next != NULL)
	{
		content = content->next;
	}
	return (content);
}
