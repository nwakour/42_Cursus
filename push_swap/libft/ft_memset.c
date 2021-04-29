/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:58:35 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/13 17:35:30 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t n)
{
	char			a;
	unsigned char	*p;

	a = x;
	p = (unsigned char *)str;
	while (n--)
		*p++ = a;
	return (str);
}
