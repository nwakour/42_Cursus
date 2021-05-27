/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:00:26 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/25 15:41:35 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    print_t_ilists(short *a, short *b, short a_start, short b_start, short a_end, short b_end)
{
    printf("\t ____________________________ \n");
    printf("\t|____ %c _____|\t|____ %c _____|\n",
        'a', 'b');
    while (a_start < a_end || b_start < b_end)
    {
        if (a_start < a_end && b_start < b_end)
            printf("\t[%11d ]\t[%11d ]\n", a[a_start++], b[b_start++]);
        else if (a_start < a_end)
        {
            printf("\t[%11d ]\t[%11c ]\n", a[a_start++], ' ');
        }
       else if (b_start < b_end)
        {
            printf("\t[%11c ]\t[%11d ]\n", ' ', b[b_start++]);
        }
    }
    printf("\t------------------------------\n");
}


int main()
{
	
	short *a;
	short *b;
	short size = 5;
	short a_start;
	short b_start;
	short a_end;
	short b_end;

	a = (short*)malloc(sizeof(int) * size * 5);
	b = (short*)malloc(sizeof(int) * size * 5);
	
	a_start = size * 2;
	a_end = size * 3;
	b_start = size * 3;
	b_end = size * 3;

	a[10] = 8;
	a[11] = 2;
	a[12] = 6;
	a[13] = 5;
	a[14] = 4;

	print_t_ilists(a, b, a_start, b_start, a_end, b_end);
	push(b,a, &b_start, &a_start);
	push(b,a, &b_start, &a_start);
	rotate(a, &a_start, &a_end);
	rotate(b, &b_start, &b_end);
	swap(a, a_start);
	swap(b, b_start);
	push(a,b, &a_start, &b_start);
	push(a,b, &a_start, &b_start);
	rotate(a, &a_start, &a_end);
	print_t_ilists(a, b, a_start, b_start, a_end, b_end);
	// push(b,a, &a_start, &b_start);
	// push(&b,&a);
	// rotate(&a);
	// rotate(&b);
	// swap(&a);
	// swap(&b);
	// push(&a,&b);
	// push(&a,&b);
	// rotate(&a);
	
	
	// print_new_t_ilists(a,b,6, 0);

	return (0);
}