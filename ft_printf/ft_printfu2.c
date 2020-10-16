/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:50:16 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:50:17 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_writenchru(t_flags *fl)
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

void	ft_printfuwidth(char *s, t_flags *fl)
{
	int		len;
	char	*f;
	char	*str;

	len = ft_strlen(s);
	if (len < fl->wwf)
		fl->wwf -= len;
	else
		fl->wwf = 0;
	if (fl->zf != 0)
	{
		fl->wwwf = fl->wwf;
		fl->wwf = 0;
	}
	f = ft_writenchru(fl);
	if (fl->mf == 0)
		str = ft_strjoin(f, s);
	else
		str = ft_strjoin(s, f);
	ft_putstr(str, fl, 0);
	ft_free_return(&f, &str, NULL, 0);
}

void	ft_printfuprecision(char *s, t_flags *fl)
{
	int		len;
	char	*f;
	char	*str;

	len = ft_strlen(s);
	if (len < fl->wwwf)
		fl->wwwf -= len;
	else
		fl->wwwf = 0;
	f = ft_writenchru(fl);
	str = ft_strjoin(f, s);
	ft_putstr(str, fl, 0);
	ft_free_return(&f, &str, NULL, 0);
}

void	ft_printfu2(t_flags *fl, unsigned int u, char *s)
{
	if (fl->wwwf < 0 && fl->zf == 0)
		fl->wwwf = 0;
	if (fl->wwwf < 0 && fl->zf != 0 && fl->mf == 0)
		fl->wwwf = fl->wwf;
	if (u == 0 && fl->pf != 0 && fl->wf == 0 &&
		(fl->wpf == 0 || (fl->wwwf == 0 && fl->wpf == 0)))
		return ;
	if (fl->mf != 0 && fl->zf != 0)
		fl->zf = 0;
	if (fl->wf != 0 && fl->pf == 0 && fl->wpf == 0)
		ft_printfuwidth(s, fl);
	else if (fl->pf != 0 && fl->wpf != 0 && fl->wf == 0)
		ft_printfuprecision(s, fl);
	else if (fl->pf != 0 && fl->wf != 0)
		ft_printfuboth(s, fl);
	else if (fl->nf == 1 || fl->zf != 0
		|| (fl->pf != 0 && fl->wpf == 0) || fl->mf != 0)
		ft_putnbr(u);
	ft_free_return(NULL, &s, NULL, 0);
}
