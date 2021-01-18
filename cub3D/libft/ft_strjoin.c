/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:57:31 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/15 17:05:50 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[i] != 0)
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
