/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:01:58 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/13 19:24:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/cub3d.h"

void	freee_content(void *content)
{
	char *s;

	s = (char*)content;
	if ((char*)content)
	{
		free((char*)content);
		content = 0;
	}
}

int		main(void)
{
	t_list	*list;
	t_list	*tmp;
	char	*s;
	int		i;

	list = ft_lstnew(ft_strdup("allo"));
	i = -1;
	while (++i < 10)
	{
		ft_lstadd_back(&list, ft_lstnew(ft_strdup("hello")));
	}
	i = -1;
	tmp = list;
	while (tmp)
	{
		s = tmp->content;
		printf("%d %s\n", ++i, s);
		tmp = tmp->next;
	}
	ft_lstclear_last(&list, freee_content);
	i = -1;
	tmp = list;
	while (tmp)
	{
		s = tmp->content;
		printf("%d %s\n", ++i, s);
		tmp = tmp->next;
	}
	return (0);
}
