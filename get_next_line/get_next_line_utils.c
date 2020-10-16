/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:56:54 by nwakour           #+#    #+#             */
/*   Updated: 2019/11/18 19:56:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*cp;
	char			*str1;

	i = 0;
	j = 0;
	str1 = (char*)str;
	while (str[i] != '\0')
	{
		i++;
	}
	if (!(cp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < (sizeof(char) * i))
	{
		cp[j] = str[j];
		j++;
	}
	cp[j] = '\0';
	return (cp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != 0)
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		if (!(str = (char*)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = ((char*)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
