/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:47:31 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/12 18:53:48 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	s = (char*)str;
	if (c == '\0')
	{
		return (s + i);
	}
	while (i != 0)
	{
		if (s[i] == (char)c)
		{
			return (s + i);
		}
		i--;
	}
	if (s[0] == (char)c)
	{
		return (s);
	}
	return (NULL);
}
