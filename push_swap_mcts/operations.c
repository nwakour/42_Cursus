/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/01 12:56:48 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(short *stack, short start)
{
	short nb;

	nb = stack[start];
	stack[start] = stack[(start + 1)];
	stack[start + 1] = nb;
}

void push(short *a, short *b, short *a_start, short *b_start)
{
	a[--(*a_start)] = b[(*b_start)++];
}

void rotate(short *stack, short *start, short *end)
{
	stack[(*end)++] = stack[(*start)++];
}

void rev_rotate(short *stack, short *start, short *end)
{
	stack[--(*start)] = stack[--(*end)];
}
