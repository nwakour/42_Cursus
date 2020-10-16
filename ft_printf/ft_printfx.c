/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:50:27 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:50:28 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_writebothx(char *s, t_flags *fl)
{
	char	*f;
	char	*str;
	char	*z;
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
		str = ft_strjoin(f, str);
	else if (fl->mf != 0)
		str = ft_strjoin(str, f);
	return (str);
}

void	ft_printfxboth(char *s, t_flags *fl)
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
	str = ft_writebothx(s, fl);
	ft_putstr(str, fl, 0);
	ft_free_return(NULL, &str, NULL, 0);
}

void	ft_printfx(va_list args, char add, t_flags *fl)
{
	unsigned int	x;
	char			*hex;

	if (fl->vf != 0)
		fl->wwf = va_arg(args, unsigned int);
	if (fl->vpf != 0)
		fl->wwwf = va_arg(args, unsigned int);
	x = va_arg(args, unsigned int);
	if (x == 0 && fl->pf != 0 && fl->wwf == 0 && fl->wwwf == 0)
		return ;
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	hex = ft_hexaconv(x, add);
	ft_strrev(hex);
	if (x == 0 && fl->wwwf == 0 && fl->pf != 0 && fl->wf != 0)
		hex[0] = ' ';
	ft_printfx2(fl, x, hex);
}
