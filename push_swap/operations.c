/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/16 16:29:14 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *stack, int start)
{
	int nb;

	nb = stack[start];
	stack[start] = stack[(start + 1)];
	stack[start + 1] = nb;
}

void push(int *a, int *b, int *a_start, int *b_start)
{
	a[--(*a_start)] = b[(*b_start)++];
}

void rotate(int *stack, int *start, int *end)
{
	stack[(*end)++] = stack[(*start)++];
}

void rev_rotate(int *stack, int *start, int *end)
{
	stack[--(*start)] = stack[--(*end)];
}
