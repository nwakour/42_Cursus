/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:55:40 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/25 15:50:56 by nwakour          ###   ########.fr       */
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