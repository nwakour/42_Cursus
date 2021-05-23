/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/23 19:57:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int g_nb = 2147483647;

static void free_all(t_ilist **a, t_ilist **b, int *done)
{
	t_ilist *next_node;
	t_ilist *current;

	if (done)
		free(done);
	done = NULL;
	next_node = (*a);
	current = (*a);
	while (next_node)
	{
		current = next_node;
		next_node = next_node->next;
		free(current);
	}
	next_node = (*b);
	current = (*b);
	while (next_node)
	{
		current = next_node;
		next_node = next_node->next;
		free(current);
	}
}

static int is_sorted(t_ilist *a, t_ilist *b, int *done, int nnb)
{
	t_ilist *tmp;
	int nb;
	// print_t_ilists(a, b);
	if (!a)
		return (0);
	tmp = a;
	nb = tmp->nb;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (nb > tmp->nb)
			return (0);
		else
			nb = tmp->nb;
	}
	if (b)
		return (0);
	// if (nnb < g_nb)
	// 	g_nb = nnb;
	(void)done;
	if (nnb <= g_nb)
	{
		g_nb = nnb;
		printf("{");
		for (int i = 0; done[i] != 0; ++i)
			printf("%d,", done[i]);
		printf("}\n");
		// print_t_ilists(a, b);
		printf("%d\n", g_nb);
	}
	// free_all(&a, &b, done);
	return (1);
}

static void add_poss(int *opper, int add)
{
	int i;

	i = 0;
	while (i < 11 && opper[i] != 0)
		i++;
	opper[i] = add;
	if (i < 10)
		opper[++i] = 0;
}

static int is_poss(t_ilist *a, t_ilist *b, int *opper, int last)
{
	int a_len;
	int b_len;
	int poss_nb;

	a_len = ft_int_lstsize(a);
	b_len = ft_int_lstsize(b);
	poss_nb = 0;
	if (a_len > 1)
	{
		if (last != SA)
		{
			add_poss(opper, SA);
			poss_nb += 1;
		}
		if (last != RRA)
		{
			add_poss(opper, RA);
			poss_nb += 1;
		}
		if (last != RA)
		{
			add_poss(opper, RRA);
			poss_nb += 1;
		}
	}
	if (b_len > 1)
	{
		if (last != SB)
		{
			add_poss(opper, SB);
			poss_nb += 1;
		}
		if (last != RRB)
		{
			add_poss(opper, RB);
			poss_nb += 1;
		}
		if (last != RB)
		{
			add_poss(opper, RRB);
			poss_nb += 1;
		}
	}
	if (b_len > 1 && a_len > 1)
	{
		if (last != SS)
		{
			add_poss(opper, SS);
			poss_nb += 1;
		}
		if (last != RRR)
		{
			add_poss(opper, RR);
			poss_nb += 1;
		}
		if (last != RR)
		{
			add_poss(opper, RRR);
			poss_nb += 1;
		}
	}
	if (b_len > 0 && last != PB)
	{
		add_poss(opper, PA);
		poss_nb += 1;
	}
	if (a_len > 0 && last != PA)
	{
		add_poss(opper, PB);
		poss_nb += 1;
	}
	return poss_nb;
}

static void cp_list(t_ilist *list, t_ilist **cp)
{
	t_ilist *tmp;
	tmp = list;

	while (tmp)
	{
		ft_int_lstadd_back(cp, ft_int_lstnew(tmp->nb));
		tmp = tmp->next;
	}
}

static void add_done(int *done, int opper)
{
	int i;
	i = 0;
	
	while (done[i] != 0)
		i++;
	done[i] = opper;
	done[++i] = 0;
}

static void corr_ai_op(t_ilist **a, t_ilist **b, int opper, int *done, int *nb, int *last)
{

	if (opper == SA)
		swap(a);
	else if (opper == SB)
		swap(b);
	else if (opper == SS)
	{
		swap(a);
		swap(b);
	}
	else if (opper == PA)
		push(a, b);
	else if (opper == PB)
		push(b, a);
	else if (opper == RA)
		rotate(a);
	else if (opper == RB)
		rotate(b);
	else if (opper == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (opper == RRA)
		rev_rotate(a);
	else if (opper == RRB)
		rev_rotate(b);
	else if (opper == RRR)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	(*last) = opper;
	add_done(done, opper);
	(*nb)++;
}

static int inter(t_ilist *a, t_ilist *b, int sorted, int *dones, int nb, int last)
{
	int opper[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	t_ilist *cp_a;
	t_ilist *cp_b;
	int poss_nb;
	int random;
	int *other_dones;

	srand(time(NULL));
	if (sorted || nb > 1000)
	{
		free_all(&a, &b, dones);
		return (1);
	}
	opper[0] = 0;
	poss_nb = is_poss(a, b, opper, last);
	if (poss_nb == 0)
		return (1);
	// int save = poss_nb;
	// int old_last = last;
	for (int i = 0; i < 11; ++i)
	{
		cp_a = NULL;
		cp_b = NULL;
		other_dones = (int*)malloc(sizeof(int) * 1001);
		other_dones[0] = 0;
		for (int j = 0; dones[j] != 0; ++j)
		{
			other_dones[j] = dones[j];
			if (dones[j + 1] == 0)
				other_dones[j + 1] = 0;
		}
		// printf("d\n");
		cp_list(a, &cp_a);
		cp_list(b, &cp_b);
		random = ((rand() % poss_nb));
		corr_ai_op(&cp_a, &cp_b, opper[random], other_dones, &nb, &last);
		opper[random] = opper[poss_nb - 1];
		opper[poss_nb - 1] = 0;
		poss_nb--;
		inter(cp_a, cp_b, is_sorted(cp_a, cp_b, other_dones, nb), other_dones, nb, last);
		if (poss_nb == 0)
			break;
		// last = old_last;
		// opper[0] = 0;
		// poss_nb = is_poss(a, b, opper, last);
		nb--;
	}
	free_all(&a, &b, dones);
	return 1;
}

int ai(t_ilist *a, t_ilist *b)
{
	int *done;
	done = (int *)malloc(sizeof(int) * 1001);
	done[0] = 0;
	inter(a, b, 0, done, 0, 0);
	return (g_nb);
}