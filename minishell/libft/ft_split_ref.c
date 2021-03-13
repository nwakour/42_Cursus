/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ref.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 06:45:50 by nwakour           #+#    #+#             */
/*   Updated: 2021/03/13 18:59:35 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_wordnbr(char const *s, char c)
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

static int			ft_fndlen(char const *s, char c)
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

static void			ft_free(char **str)
{
	while (*str != NULL)
	{
		free(*str);
		str++;
	}
	free(str);
}

static void			ft_allo(char **str, const char *src, const char *ref, char c)
{
	char	*res;

	if (!(*str = malloc((ft_fndlen(src, c) + 1) * sizeof(char))))
	{
		ft_free(str);
		return ;
	}
	res = *str;
	while (*ref != c && *ref)
	{
		*res = *src;
		ref++;
		res++;
		src++;
	}
	*res = '\0';
}

char				**ft_split_ref(char const *s, char const *ref, char c)
{
	char	**str;
	char	**res;
	int		i;

	if (!s || !ref || !(str = malloc((ft_wordnbr(ref, c) + 1) * sizeof(char *))))
		return (NULL);
	res = str;
	i = 0;
	while (*ref)
	{
		if (*ref != c && i == 0)
		{
			i = 1;
			ft_allo(str, s, ref, c);
			str++;
		}
		if (*ref == c && i == 1)
			i = 0;
		s++;
		ref++;
	}
	*str = NULL;
	return (res);
}
