/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:42:28 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/13 18:19:37 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, void *str2, int c, size_t n)
{
	unsigned char	*str1a;
	unsigned char	*str2a;
	unsigned char	s;
	size_t			i;

	i = 0;
	str1a = (unsigned char *)str1;
	str2a = (unsigned char *)str2;
	s = (unsigned char)c;
	while (i < n)
	{
		str1a[i] = str2a[i];
		if (str2a[i] == s)
			return (str1 + i + 1);
		i++;
	}
	return (NULL);
}
