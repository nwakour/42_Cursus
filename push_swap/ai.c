/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/22 21:25:53 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int g_nb = 2147483647;

static void free_all(t_ilist **a, t_ilist **b, char **done)
{
	t_ilist *next_node;
	t_ilist *current;

	if (done && *done)
		free(*done);
	*done = NULL;
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

static int is_sorted(t_ilist *a, t_ilist *b, char *done, int nnb)
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
	
	(void)done;
	// if (nnb < g_nb)
	// 	g_nb = nnb;
	if (nnb <= g_nb)
	{
		g_nb = nnb;
		printf("%s\n", done);
		print_t_ilists(a, b);
		printf("%d\n", nnb);
	}
	free_all(&a, &b, &done);
	return (1);
}

static void add_poss(char **oper, char *add)
{
	int i;

	i = 0;
	while (oper[i] && oper[i][0] != 'z')
		i++;
	oper[i][0] = add[0];
	oper[i][1] = add[1];
	oper[i][2] = add[2];
	if (i < 10)
		oper[++i][0] = 'z';
}

static int is_poss(t_ilist *a, t_ilist *b, char **oper)
{
	int a_len;
	int b_len;
	int poss_nb;

	a_len = ft_int_lstsize(a);
	b_len = ft_int_lstsize(b);
	poss_nb = 0;
	if (a_len > 1)
	{
		add_poss(oper, "sa");
		add_poss(oper, "ra");
		add_poss(oper, "rra");
		poss_nb += 3;
	}
	if (b_len > 1)
	{
		add_poss(oper, "sb");
		add_poss(oper, "rb");
		add_poss(oper, "rrb");
		poss_nb += 3;
	}
	if (b_len > 1 && a_len > 1)
	{
		add_poss(oper, "ss");
		add_poss(oper, "rr");
		add_poss(oper, "rrr");
		poss_nb += 3;
	}
	if (b_len > 0)
	{
		add_poss(oper, "pa");
		poss_nb += 1;
	}
	if (a_len > 0)
	{
		add_poss(oper, "pb");
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

static void add_done(char **done, char *opp)
{
	int i;
	int len;
	int j;

	i = 0;
	j = 0;
	len = ft_strlen(opp);
	
	while ((*done)[i])
		i++;
	while (j < len)
	{
		(*done)[i] = opp[j];
		j++;
		i++;
	}
	(*done)[i] = '\n';
	(*done)[++i] = '\0';
}

static void corr_ai_op(t_ilist **a, t_ilist **b, char *opp, char **done, int *nb)
{
	if (opp[0] == 's')
	{
		if (opp[1] == 'a' && opp[2] == '\0')
			swap(a);
		else if (opp[1] == 'b' && opp[2] == '\0')
			swap(b);
		else if (opp[1] == 's' && opp[2] == '\0')
		{
			swap(a);
			swap(b);
		}
	}
	else if (opp[0] == 'p')
	{
		if (opp[1] == 'a' && opp[2] == '\0')
			push(a, b);
		else if (opp[1] == 'b' && opp[2] == '\0')
			push(b, a);
	}
	else if (opp[0] == 'r' && opp[2] == '\0')
	{
		if (opp[1] == 'a')
			rotate(a);
		else if (opp[1] == 'b')
			rotate(b);
		else if (opp[1] == 'r')
		{
			rotate(a);
			rotate(b);
		}
	}
	else if (opp[0] == 'r' && opp[1] == 'r')
	{
		if (opp[2] == 'a' && opp[3] == '\0')
			rev_rotate(a);
		else if (opp[2] == 'b' && opp[3] == '\0')
			rev_rotate(b);
		else if (opp[2] == 'r' && opp[3] == '\0')
		{
			rev_rotate(a);
			rev_rotate(b);
		}
	}
	add_done(done, opp);
	(*nb)++;
}

static int inter(t_ilist *a, t_ilist *b, int sorted, char **oper, char **done, int nb)
{
	t_ilist *cp_a = NULL;
	t_ilist *cp_b = NULL;
	int poss_nb;
	int random;
	char *other_done;

	if (sorted)
		return (1);
	if (nb > 100)
		return (0);
	other_done = (char *)malloc(sizeof(char) * 100000);
	for (int i = 0; (*done)[i] != '\0'; ++i)
	{
		other_done[i] = (*done)[i];
		if ((*done)[i + 1] == '\0')
			other_done[i + 1] = '\0';
	}
	if ((*done)[0] == '\0')
			other_done[0] = '\0';
	cp_list(a, &cp_a);
	cp_list(b, &cp_b);
	oper[0][0] = 'z';
	poss_nb = is_poss(cp_a, cp_b, oper);
	// if (poss_nb == 0)
	// 	return 0;
	// else
	random = ((rand() % poss_nb));
	corr_ai_op(&cp_a, &cp_b, oper[random], &other_done, &nb);
	free_all(&a, &b, done);
	return (inter(cp_a, cp_b, is_sorted(cp_a, cp_b, other_done, nb), oper, &other_done ,nb));
}

int ai(t_ilist *a, t_ilist *b)
{
	char *oper[] = {"sa","sb","ss","pa","pb","ra","rb","rr","rra","rrb","rrr"};
	char **opper;
	char *done;
	done = (char *)malloc(sizeof(char) * 100000);
	done[0] = '\0';
	opper = (char **)malloc(sizeof(char*) * 12);
	for (int i = 0; i < 11; ++i)
	{
		opper[i] = ft_strdup(oper[i]);
	}
	opper[11] = NULL;
	inter(a, b, 0, opper, &done, 0);
	for (int i = 0; i < 12; ++i)
	{
		free(opper[i]);
	}
	// free(done);
	free(opper);
	// printf("%d\n", g_nb);
	return (g_nb);
}