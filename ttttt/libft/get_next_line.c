/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:57:11 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/21 17:30:37 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_return(char **ptr, char **ptr2, char **ptr3, int i)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (ptr2 != NULL)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	if (ptr3 != NULL)
	{
		free(*ptr3);
		*ptr3 = NULL;
	}
	return (i);
}

static char	*ft_smartstrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char*)str;
	while (i <= (int)ft_strlen(str))
	{
		if (*s == c)
		{
			*s = '\0';
			return (s);
		}
		s++;
		i++;
	}
	return (NULL);
}

static int	checking(char **line, int fd)
{
	if (fd < 0 || fd > OPEN_MAX || line == NULL
		|| 1000 <= 0 || read(fd, NULL, 0))
		return (-1);
	if ((*line = ft_strdup("")) == NULL)
		return (-1);
	return (0);
}

static int	ft_write_buf(int fd, char **sta, char **line)
{
	int		j;
	char	*buf;
	char	*s;
	char	*c;

	if (!(buf = malloc(sizeof(char) * (1000 + 1))))
		return (free_return(line, NULL, NULL, -1));
	j = read(fd, buf, 1000);
	buf[j] = '\0';
	c = *sta;
	*sta = ft_strjoin(*sta, buf);
	free_return(NULL, &c, NULL, 1);
	c = *line;
	if (j == 0 && ft_strlen(*sta) == 0)
		return (free_return(&buf, NULL, NULL, j));
	if ((s = ft_smartstrchr(*sta, '\n')) != NULL)
	{
		*line = ft_strjoin(*line, *sta);
		free_return(NULL, &c, NULL, -2);
		c = *sta;
		*sta = ft_strdup(s + 1);
		return ((free_return(&buf, &c, NULL, -2)));
	}
	*line = ft_strjoin(*line, *sta);
	return ((free_return(&buf, &c, sta, j)));
}

int			get_next_line(int fd, char **line)
{
	int			i;
	static char	*sta[OPEN_MAX] = {0};
	char		*s;

	i = 1;
	if (checking(line, fd) == -1)
		return (-1);
	while (i != 0)
	{
		if (sta[fd] != 0)
			i = ft_write_buf(fd, &sta[fd], line);
		else
		{
			if (!(sta[fd] = malloc(sizeof(char) * (1000 + 1))))
				return ((free_return(NULL, line, NULL, -1)));
			s = sta[fd];
			if ((sta[fd] = ft_strdup("")) == NULL)
				return ((free_return(NULL, line, NULL, -1)));
			free_return(NULL, &s, NULL, -1);
			i = ft_write_buf(fd, &sta[fd], line);
		}
		if (i == -2)
			return (1);
	}
	return (0);
}
