/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:32:53 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:47:51 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	char			*cp;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	if (i > size)
		i = size;
	cp = (char *)malloc(sizeof(char) * (i + 1));
	if (!cp)
		return (NULL);
	while (j < (sizeof(char) * i))
	{
		cp[j] = str[j];
		j++;
	}
	cp[j] = '\0';
	return (cp);
}
