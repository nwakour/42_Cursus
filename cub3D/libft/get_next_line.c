/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:57:11 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/12 17:20:08 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		newline(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		free_memory(char **p1, char **p2, int nb, int ret)
{
	free(*p1);
	*p1 = 0;
	if (nb)
	{
		free(*p2);
		*p2 = 0;
	}
	if (ret < 0)
		return (-1);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*txt[20000];
	char		*b;
	char		*p;
	int			r;

	if (fd < 0 || !line || 1000 < 1 || !(b = malloc(1000 + 1)))
		return (-1);
	if (!txt[fd])
		txt[fd] = ft_strdup("");
	while (!(ft_strchr(txt[fd], '\n')) && ((r = read(fd, b, 1000)) > 0))
	{
		b[r] = '\0';
		p = txt[fd];
		txt[fd] = ft_strjoin(txt[fd], b);
		free(p);
	}
	if (ft_strchr(txt[fd], '\n'))
	{
		*line = ft_substr(txt[fd], 0, newline(txt[fd]));
		p = txt[fd];
		txt[fd] = ft_strdup(txt[fd] + newline(txt[fd]) + 1);
		return (free_memory(&p, &b, 2, 1));
	}
	*line = ft_strdup(txt[fd]);
	return (free_memory(&txt[fd], &b, 2, (r != -1 ? 0 : -1)));
}
