/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:48:54 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 16:19:43 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*element;

	element = lst;
	if (element)
	{
		while (element != NULL)
		{
			f(element->content);
			element = element->next;
		}
	}
}
