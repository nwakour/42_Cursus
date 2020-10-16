/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:49:49 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:49:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfsboth(char *s, t_flags *fl)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > (size_t)fl->wwwf)
		len = fl->wwwf;
	else if (len <= (size_t)fl->wwwf)
		fl->wwwf = len;
	if (len > (size_t)fl->wwf)
		fl->wwf = 0;
	else if (len <= (size_t)fl->wwf)
		fl->wwf -= len - 1;
	ft_printfswrite(s, fl);
}

int		ft_printfs(va_list args, t_flags *fl)
{
	char	*s;
	int		i;

	i = 0;
	if (fl->vf != 0)
		fl->wwf = va_arg(args, int);
	if (fl->vpf != 0)
		fl->wwwf = va_arg(args, int);
	s = va_arg(args, char*);
	if (!s)
	{
		s = ft_strdup("(null)");
		i = 1;
	}
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	if (fl->wwwf < 0)
	{
		fl->pf = 0;
		fl->wf = 1;
	}
	return (ft_printfs2(fl, i, s));
}
