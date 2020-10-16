/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:52:51 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:52:52 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isflags(const char *f, t_flags *fl)
{
	while (f[fl->i] == '-' || f[fl->i] == '0')
	{
		if (f[fl->i] == '-')
			fl->mf = 1;
		if (f[fl->i] == '0')
			fl->zf = 1;
		fl->i++;
	}
}

void	ft_iswidth(const char *f, t_flags *fl)
{
	while (f[fl->i] >= '0' && f[fl->i] <= '9')
	{
		fl->wwf = (fl->wwf * 10) + f[fl->i] - 48;
		fl->wf = 1;
		fl->i++;
	}
	if (f[fl->i] == '*')
	{
		fl->vf = 1;
		fl->wf = 1;
		fl->i++;
	}
}

void	ft_isprecision(const char *f, t_flags *fl)
{
	if (f[fl->i] == '.')
	{
		fl->pf = 1;
		fl->i++;
	}
	while (f[fl->i] >= '0' && f[fl->i] <= '9' && fl->pf != 0)
	{
		fl->wwwf = (fl->wwwf * 10) + f[fl->i] - 48;
		fl->wpf = 1;
		fl->i++;
	}
	if (f[fl->i] == '*' && fl->pf != 0)
	{
		fl->vpf = 1;
		fl->wpf = 1;
		fl->i++;
	}
}

void	ft_structflags(const char *f, t_flags *fl)
{
	ft_isflags(&f[0], fl);
	ft_iswidth(&f[0], fl);
	ft_isprecision(&f[0], fl);
	if (fl->mf == 0 && fl->pf == 0 && fl->vf == 0 && fl->zf == 0
		&& fl->wf == 0 && fl->wpf == 0 && fl->vpf == 0)
		fl->nf = 1;
}
