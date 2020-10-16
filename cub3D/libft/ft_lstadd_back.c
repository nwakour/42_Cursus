/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:44:48 by nwakour           #+#    #+#             */
/*   Updated: 2019/11/06 12:44:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	last = *alst;
	new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
