/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:41:17 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/13 14:53:42 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!src || !size)
		return (ft_strlen(src));
	if (src)
	{
		i = -1;
		while ((size_t)++i < size - 1 && src[i] != '\0')
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
