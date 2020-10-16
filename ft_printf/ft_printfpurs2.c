/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpurs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:49:40 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:49:41 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_writenchrpurs(t_flags *fl)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	if (fl->wwf > fl->wwwf)
		len = fl->wwf;
	else
		len = fl->wwwf;
	if (ft_alloc_char(&s, len) == NULL)
		return (NULL);
	while (i < fl->wwf)
		s[i++] = ' ';
	while (i < fl->wwwf)
		s[i++] = '0';
	s[i] = '\0';
	return (s);
}

void	ft_printfpurswidth(t_flags *fl)
{
	int		len;
	char	*f;

	len = 1;
	if (len < fl->wwf)
		fl->wwf -= len;
	else
		fl->wwf = 0;
	if (fl->zf != 0)
	{
		fl->wwwf = fl->wwf;
		fl->wwf = 0;
	}
	f = ft_writenchrpurs(fl);
	if (fl->mf == 0)
	{
		ft_putstr(f, fl, 0);
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		ft_putstr(f, fl, 0);
	}
	ft_free_return(&f, NULL, NULL, 0);
}

void	ft_printfpursprecision(t_flags *fl)
{
	int		len;
	char	*f;

	len = 1;
	if (len < fl->wwwf)
		fl->wwwf -= len;
	else
		fl->wwwf = 0;
	f = ft_writenchrpurs(fl);
	ft_putstr(f, fl, 0);
	ft_putchar('%');
	ft_free_return(&f, NULL, NULL, 0);
}

void	ft_printfpurs2(t_flags *fl)
{
	if (fl->wwwf < 0 && fl->zf == 0)
		fl->wwwf = 0;
	if (fl->wwwf < 0 && fl->zf != 0 && fl->mf == 0)
		fl->wwwf = fl->wwf;
	if (fl->pf != 0 && fl->wf == 0 &&
		(fl->wpf == 0 || (fl->wwwf == 0 && fl->wpf == 0)))
		return ;
	if (fl->mf != 0 && fl->zf != 0)
		fl->zf = 0;
	if (fl->wwwf != 0)
		fl->wwwf = 0;
	if (fl->zf != 0)
		fl->wwwf = fl->wwf;
	if (fl->wf != 0 && fl->pf == 0 && fl->wpf == 0)
		ft_printfpurswidth(fl);
	else if (fl->pf != 0 && fl->wpf != 0 && fl->wf == 0)
		ft_printfpursprecision(fl);
	else if (fl->pf != 0 && fl->wf != 0)
		ft_printfpursboth(fl);
	else if (fl->nf == 1 || fl->zf != 0
		|| (fl->pf != 0 && fl->wpf == 0) || fl->mf != 0)
		ft_putchar('%');
}
