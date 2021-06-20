/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:55:40 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/16 16:29:46 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_t_ilists(int *a, int *b, int a_start, int b_start, int a_end, int b_end)
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