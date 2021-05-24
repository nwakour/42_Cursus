/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:55:40 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/24 21:15:52 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_t_ilists(t_ilist *a, t_ilist *b, int size_a, int size_b)
{
    printf("\t ____________________________ \n");
    printf("\t|____ %c _____|\t|____ %c _____|\n",
        'a', 'b');
    while (size_a || size_b)
    {
        if (size_a && size_b)
        {
            printf("\t[%11d ]\t[%11d ]\n", a->nb, b->nb);
            a = a->next;
            b = b->next;
			size_a--;
			size_b--;
        }
        else if (size_a && !size_b)
        {
            printf("\t[%11d ]\t[%11c ]\n", a->nb, ' ');
            a = a->next;
			size_a--;
        }
        else if (size_b && !size_a)
        {
            printf("\t[%11c ]\t[%11d ]\n", ' ', b->nb);
            b = b->next;
			size_b--;
        }
    }
    printf("\t------------------------------\n");
}
