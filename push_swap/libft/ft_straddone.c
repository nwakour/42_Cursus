/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:22:25 by nwakour           #+#    #+#             */
/*   Updated: 2021/04/07 17:55:46 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddone(const char *str, size_t d, char c)
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
	if (!(cp = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	while (j < (sizeof(char) * (i + 1)))
	{
		if (z == d)
		{	
			cp[z] = c;
			z++;
		}
		else
		{
			cp[z] = str[j];
			j++;
			z++;
		}
	}
	cp[z] = '\0';
	return (cp);
}
