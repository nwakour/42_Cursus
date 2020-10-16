/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:12:09 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/13 19:23:53 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, void *str2, size_t n)
{
	unsigned char	*str1a;
	unsigned char	*str2a;

	str1a = (unsigned char *)str1;
	str2a = (unsigned char *)str2;
	if (!str2 && !str1)
		return (0);
	while (n--)
		*str1a++ = *str2a++;
	return (str1);
}
