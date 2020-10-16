/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:50:08 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:50:09 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_writebothu(char *s, t_flags *fl)
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
	while (i < fl->wwwf)
		z[i++] = '0';
	z[i] = '\0';
	str = ft_strjoin(z, s);
	if (fl->mf == 0)
		strr = ft_strjoin(f, str);
	else
		strr = ft_strjoin(str, f);
	ft_free_return(&z, &f, &str, 0);
	return (strr);
}

void	ft_printfuboth(char *s, t_flags *fl)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	if (len < fl->wwwf)
		fl->wwwf -= len;
	else
		fl->wwwf = 0;
	if (len < fl->wwf)
		fl->wwf -= len + fl->wwwf;
	else
		fl->wwf = 0;
	if (fl->wwf < 0)
		fl->wwf = 0;
	str = ft_writebothu(s, fl);
	ft_putstr(str, fl, 0);
	ft_free_return(NULL, &str, NULL, 0);
}

void	ft_printfu(va_list args, t_flags *fl)
{
	unsigned int	u;
	char			*s;

	if (fl->vf != 0)
		fl->wwf = va_arg(args, unsigned int);
	if (fl->vpf != 0)
		fl->wwwf = va_arg(args, unsigned int);
	u = va_arg(args, unsigned int);
	if (u == 0 && fl->pf != 0 && fl->wwf == 0 && fl->wwwf == 0)
		return ;
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	s = ft_itoa(u);
	if (u == 0 && fl->wwwf == 0 && fl->pf != 0 && fl->wf != 0)
		s[0] = ' ';
	ft_printfu2(fl, u, s);
}
