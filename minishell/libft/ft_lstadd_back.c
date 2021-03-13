/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:44:48 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/03 16:28:36 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *l_new)
{
	t_list	*last;

	if (!l_new)
		return ;
	last = *alst;
	l_new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = l_new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = l_new;
	}
}
