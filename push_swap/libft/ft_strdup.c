/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:25:53 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:46:08 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*cp;

	i = 0;
	j = -1;
	while (str[i] != '\0')
		i++;
	cp = (char *)malloc(sizeof(char) * (i + 1));
	if (!cp)
		return (NULL);
	while (++j < (sizeof(char) * i))
		cp[j] = str[j];
	cp[j] = '\0';
	return (cp);
}
