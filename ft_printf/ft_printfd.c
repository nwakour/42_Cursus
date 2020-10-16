/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:49:09 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:49:10 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_writedboth(int d, char *s, t_flags *fl)
{
	char	*f;
	char	*str;
	char	*z;
	char	*strr;
	int		i;

	i = 0;
	if (ft_alloc_char(&f, fl->wwf) == NULL)
		return (NULL);
	if (ft_alloc_char(&z, fl->wwwf) == NULL)
		return (NULL);
	while (i < fl->wwf)
		f[i++] = ' ';
	f[i] = '\0';
	i = 0;
	if (d < 0 && fl->wwwf > 0)
		z[i++] = '-';
	while (i < fl->wwwf)
		z[i++] = '0';
	z[i] = '\0';
	str = ft_strjoin(z, s);
	strr = fl->mf == 0 ? ft_strjoin(f, str) : ft_strjoin(str, f);
	ft_free_return(&z, &f, &str, 0);
	return (strr);
}

void	ft_printfdboth(int d, char *s, t_flags *fl)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	if (d < 0 && fl->wwwf != 0)
		fl->wwwf++;
	if (len < fl->wwwf)
		fl->wwwf -= len;
	else
		fl->wwwf = 0;
	if (len < fl->wwf)
		fl->wwf -= len + fl->wwwf;
	else
		fl->wwf = 0;
	fl->wwf < 0 ? fl->wwf = 0 : 0;
	if (d < 0 && fl->wwf > 0 && fl->wwwf == 0)
	{
		s = ft_strjoin("-", s);
		fl->wwf--;
	}
	else if (d < 0 && fl->wwf == 0 && fl->wwwf == 0)
		s = ft_strjoin("-", s);
	str = ft_writedboth(d, s, fl);
	ft_putstr(str, fl, 0);
	ft_free_return(NULL, &str, NULL, 0);
}

void	ft_printfd(va_list args, t_flags *fl)
{
	int				d;
	char			*s;
	unsigned int	dd;

	if (fl->vf != 0)
		fl->wwf = va_arg(args, int);
	if (fl->vpf != 0)
		fl->wwwf = va_arg(args, int);
	d = va_arg(args, int);
	if (d == 0 && fl->pf != 0 && fl->wwf == 0 && fl->wwwf == 0)
		return ;
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	if (d < 0 && ((fl->zf != 0 && fl->mf == 0) || fl->pf != 0))
		dd = -d;
	if (d < 0 && ((fl->zf != 0 && fl->mf == 0) || fl->pf != 0))
		s = ft_itoa(dd);
	else
		s = ft_itoa(d);
	if (d == 0 && fl->wwwf == 0 && fl->pf != 0 && fl->wf != 0)
		s[0] = ' ';
	ft_printfd2(fl, d, s);
}
