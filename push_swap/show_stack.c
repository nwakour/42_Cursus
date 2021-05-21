/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:55:40 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/21 19:03:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_t_ilists(t_ilist *a, t_ilist *b)
{
    printf("\t ____________________________ \n");
    printf("\t|____ %c _____|\t|____ %c _____|\n",
        'a', 'b');
    while (a || b)
    {
        if (a && b)
        {
            printf("\t[%11d ]\t[%11d ]\n", a->nb, b->nb);
            a = a->next;
            b = b->next;
        }
        else if (a && !b)
        {
            printf("\t[%11d ]\t[%11c ]\n", a->nb, ' ');
            a = a->next;
        }
        else
        {
            printf("\t[%11c ]\t[%11d ]\n", ' ', b->nb);
            b = b->next;
        }
    }
    printf("\t------------------------------\n");
}
