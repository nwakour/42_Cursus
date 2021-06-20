/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:02:30 by nwakour           #+#    #+#             */
/*   Updated: 2021/04/07 17:12:55 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutone(const char *str, size_t d)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	z;
	char			*cp;
	

	i = 0;
	j = 0;
	z = 0;
	while (str[i] != '\0')
		i++;
	if (!(cp = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	while (j < (sizeof(char) * i))
	{
		if (j != d)
		{	
			cp[z] = str[j];
			z++;
		}
		j++;
	}
	cp[z] = '\0';
	return (cp);
}
