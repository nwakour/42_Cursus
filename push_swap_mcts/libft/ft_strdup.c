/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:25:53 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/15 17:05:36 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*cp;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
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
