/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_bezero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:45:37 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/06 18:25:35 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_struct_bezero(void *param, size_t size)
{
	char	*s;
	size_t	i;

	s = (char*)param;
	i = -1;
	while (++i < size)
		s[i] = 0;
}
