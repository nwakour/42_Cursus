/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:49:10 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/13 15:38:20 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*newtmp;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	new = ft_lstnew(f(tmp->content));
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (!(newtmp = ft_lstnew(f(tmp->content))))
		{
			ft_lstclear(&new, del);
			new = NULL;
			break ;
		}
		ft_lstadd_back(&new, ft_lstnew(f(tmp->content)));
		tmp = tmp->next;
	}
	return (new);
}
