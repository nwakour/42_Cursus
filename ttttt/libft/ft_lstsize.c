/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:28:16 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/21 17:28:20 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*element;

	element = lst;
	i = 0;
	while (element)
	{
		i++;
		element = element->next;
	}
	return (i);
}
