/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:49:56 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:49:57 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfswrite(char *s, t_flags *fl)
{
	if (fl->mf != 0)
	{
		ft_putstr(s, fl, 1);
		while (fl->wwf > 1)
		{
			ft_putchar(' ');
			fl->wwf--;
		}
	}
	else if (fl->mf == 0)
	{
		while (fl->wwf > 1)
		{
			ft_putchar(' ');
			fl->wwf--;
		}
		ft_putstr(s, fl, 1);
	}
}

void	ft_printfswidth(char *s, t_flags *fl)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < (size_t)fl->wwf)
	{
		fl->wwf -= len - 1;
		while (fl->wwf > 1)
		{
			ft_putchar(' ');
			fl->wwf--;
		}
		ft_putstr(s, fl, 0);
	}
	else
		ft_putstr(s, fl, 0);
}

void	ft_printfsmwidth(char *s, t_flags *fl)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < (size_t)fl->wwf)
	{
		fl->wwf -= len - 1;
		ft_putstr(s, fl, 0);
		while (fl->wwf > 1)
		{
			ft_putchar(' ');
			fl->wwf--;
		}
	}
	else
		ft_putstr(s, fl, 0);
}

void	ft_printfspressision(char *s, t_flags *fl)
{
	size_t	len;

	len = ft_strlen(s);
	if (len <= (size_t)fl->wwwf)
		ft_putstr(s, fl, 0);
	else
		ft_putstr(s, fl, 1);
}

int		ft_printfs2(t_flags *fl, int i, char *s)
{
	if (fl->zf != 0)
		return (0);
	if (fl->wf > 0 && fl->zf == 0 && fl->mf == 0 && fl->pf == 0)
		ft_printfswidth(s, fl);
	else if (fl->wf > 0 && fl->zf == 0 && fl->mf == 1 && fl->pf == 0)
		ft_printfsmwidth(s, fl);
	else if (fl->pf != 0 && fl->wf == 0)
		ft_printfspressision(s, fl);
	else if (fl->pf != 0 && fl->wf != 0)
		ft_printfsboth(s, fl);
	else if (fl->nf == 1 || fl->mf != 0)
		ft_putstr(s, fl, 0);
	if (i == 1)
		ft_free_return(&s, NULL, NULL, 0);
	return (1);
}
