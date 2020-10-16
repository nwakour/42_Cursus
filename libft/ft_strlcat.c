/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:48:53 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/13 14:56:11 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	ldst;
	size_t	lsrc;
	int		free;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dest);
	free = (int)size - (int)ldst;
	i = 0;
	j = ldst;
	if (free < 0 || size == 0)
		return (size + lsrc);
	if ((size_t)free > lsrc)
	{
		while ((size_t)i < lsrc + 1)
			dest[j++] = src[i++];
		return (ldst + lsrc);
	}
	while (free-- > 1)
		dest[j++] = src[i++];
	dest[j++] = '\0';
	return (ldst + lsrc);
}
