/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:51:48 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:51:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstrnb(char *s, t_flags *fl)
{
	int	len;

	fl->wwf = fl->wwf;
	len = ft_strlen(s);
	if (!s)
		return (1);
	if (g_len != -1)
		g_len += write(1, s, len);
	return (1);
}
