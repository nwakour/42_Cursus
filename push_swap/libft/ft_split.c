/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 06:45:50 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:38:57 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordnbr(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (*s)
	{
		if (*s != c && j == 1)
		{
			i++;
			j = 0;
		}
		if (*s == c && j == 0)
			j = 1;
		s++;
	}
	return (i);
}

static int	ft_fndlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static void	ft_free(char **str)
{
	while (*str != NULL)
	{
		free(*str);
		str++;
	}
	free(str);
}

static void	ft_allo(char **str, const char *src, char c)
{
	char	*res;

	*str = malloc((ft_fndlen(src, c) + 1) * sizeof(char));
	if (!*str)
	{
		ft_free(str);
		return ;
	}
	res = *str;
	while (*src != c && *src)
	{
		*res = *src;
		res++;
		src++;
	}
	*res = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**res;
	int		i;

	str = malloc((ft_wordnbr(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	res = str;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			ft_allo(str, s, c);
			str++;
		}
		if (*s == c && i == 1)
			i = 0;
		s++;
	}
	*str = NULL;
	return (res);
}
