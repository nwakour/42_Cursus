/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:33:15 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/17 01:35:12 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strstart(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int			ft_cntnbset(char const *s1, char const *set)
{
	int	i;
	int	nb;
	int	len;

	i = 0;
	nb = 0;
	while (ft_strstart(set, s1[i]) == 1 && s1[i])
	{
		nb++;
		i++;
	}
	len = ft_strlen(s1);
	while (ft_strstart(set, s1[len]) == 1 && len > 0)
	{
		nb++;
		len--;
	}
	return (nb);
}

static int			ft_fndend(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_strstart(set, s1[i]) == 1 && i > 0)
		i--;
	return (i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		end;
	int		len;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (ft_strstart(set, s1[start]) == 1)
		start++;
	end = ft_fndend(s1, set);
	len = ft_strlen(s1) - ft_cntnbset(s1, set);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
