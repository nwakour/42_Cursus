/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:00:26 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/22 16:02:54 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <stdlib.h>

void add1(char *str)
{
	str[5] = '2';
	printf("in %s\n", str);
}

int main()
{
	char *str;

	str = (char*)malloc(sizeof(char) * 11);
	for (int i = 0; i < 10; ++i)
	{
		str[i] = '1';
	}
	str[10] = '\0';
	printf("before %s\n", str);
	add1(str);
	printf("after %s\n", str);
}