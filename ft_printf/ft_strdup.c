/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:25:53 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/14 21:02:16 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	{
		g_len = -1;
		return (NULL);
	}
	while (j < (sizeof(char) * i))
	{
		cp[j] = str[j];
		j++;
	}
	cp[j] = '\0';
	return (cp);
}
