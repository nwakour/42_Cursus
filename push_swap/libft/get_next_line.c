/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:57:11 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 14:40:39 by nwakour          ###   ########.fr       */
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
	s = (char *)str;
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
	if (fd < 0 || fd > FOPEN_MAX || line == NULL
		|| 1000 <= 0 || read(fd, NULL, 0))
		return (-1);
	*line = ft_strdup("");
	if (!*line)
		return (-1);
	return (0);
}

static int	ft_write_buf(int fd, char **sta, char **line)
{
	int		j;
	char	*buf;
	char	*s;

	buf = malloc(sizeof(char) * (1000 + 1));
	if (!buf)
		return (free_return(line, NULL, NULL, -1));
	j = read(fd, buf, 1000);
	buf[j] = '\0';
	*sta = ft_strjoin_free(*sta, buf);
	if (j == 0 && ft_strlen(*sta) == 0)
		return (free_return(&buf, NULL, NULL, j));
	s = ft_smartstrchr(*sta, '\n');
	if (!s)
	{
		*line = ft_strjoin_free(*line, *sta);
		*sta = ft_strdup(s + 1);
		return ((free_return(&buf, NULL, NULL, -2)));
	}
	*line = ft_strjoin_free(*line, *sta);
	return ((free_return(&buf, NULL, sta, j)));
}

int	get_next_line(int fd, char **line)
{
	int			i;
	static char	*sta[FOPEN_MAX] = {0};

	i = 1;
	if (checking(line, fd) == -1)
		return (-1);
	while (i != 0)
	{
		if (sta[fd] != 0)
			i = ft_write_buf(fd, &sta[fd], line);
		else
		{
			sta[fd] = ft_strdup("");
			if (!sta[fd])
				return ((free_return(NULL, line, NULL, -1)));
			i = ft_write_buf(fd, &sta[fd], line);
		}
		if (i == -2)
			return (1);
	}
	return (0);
}
