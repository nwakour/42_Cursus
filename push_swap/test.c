/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:00:26 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/24 21:52:17 by nwakour          ###   ########.fr       */
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


int main()
{
	t_ilist *a = NULL;
	t_ilist *b = NULL;

	// a = ft_int_lstnew(1);
	ft_int_lstadd_next(&a, ft_int_lstnew(8));
	ft_int_lstadd_next(&a, ft_int_lstnew(2));
	ft_int_lstadd_next(&a, ft_int_lstnew(6));
	ft_int_lstadd_next(&a, ft_int_lstnew(5));
	ft_int_lstadd_next(&a, ft_int_lstnew(4));

	ft_int_lstadd_next(&b, ft_int_lstnew(1));
	// printf("%d\n", a->nb);
	print_t_ilists(a,b,5, 1);
	push(&b,&a);
	push(&b,&a);
	rotate(&a);
	print_t_ilists(a,b,3, 3);
	// rotate(&b);
	// swap(&a);
	// swap(&b);
	// push(&a,&b);
	// push(&a,&b);
	// rotate(&a);
	
	
	// print_new_t_ilists(a,b,6, 0);

	return (0);
}