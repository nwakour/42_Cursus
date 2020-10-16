/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 07:56:35 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/17 07:58:51 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, t_flags *fl, int i)
{
	int len;

	fl->mf = fl->mf;
	if (!s)
		return ;
	if (i == 0)
		len = ft_strlen(s);
	else
		len = fl->wwwf;
	if (g_len != -1)
		g_len += write(1, s, len);
}
