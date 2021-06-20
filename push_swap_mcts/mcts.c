/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:40:44 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/15 16:29:48 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *new_node()
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	return (new);
}

t_node *start_node()
{
	t_node *start;

	if (!(start = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	start->my_value = 0;
	start->childen = NULL;
	start->my_action = 0;
	start->parent_action = 0;
	start->parent = NULL;
	start->result = 0;
	start->state = 0;
	start->number_of_visits = 0;
	start->number_of_childen = 0;
	// start->untried_actions = 0;
	return (start);
}

static void corr_ai_op(short *a, short *b, short opper, t_index *index)
{

	if (opper == SA)
		swap(a, index->a_start);
	else if (opper == SB)
		swap(b, index->b_start);
	else if (opper == SS)
	{
		swap(a, index->a_start);
		swap(b, index->b_start);
	}
	else if (opper == PA)
		push(a, b, &index->a_start, &index->b_start);
	else if (opper == PB)
		push(b, a, &index->b_start, &index->a_start);
	else if (opper == RA)
		rotate(a, &index->a_start, &index->a_end);
	else if (opper == RB)
		rotate(b, &index->b_start, &index->b_end);
	else if (opper == RR)
	{
		rotate(a, &index->a_start, &index->a_end);
		rotate(b, &index->b_start, &index->b_end);
	}
	else if (opper == RRA)
		rev_rotate(a, &index->a_start, &index->a_end);
	else if (opper == RRB)
		rev_rotate(b, &index->b_start, &index->b_end);
	else if (opper == RRR)
	{
		rev_rotate(a, &index->a_start, &index->a_end);
		rev_rotate(b, &index->b_start, &index->b_end);
	}
}

static short is_poss(short **opper, short last, short a_len, short b_len)
{
	short index = -1;
	
	if (a_len > 1)
	{
		if (last != SA)
			(*opper)[++index] = SA;
		if (last != RRA)
			(*opper)[++index] = RA;
		if (last != RA)
			(*opper)[++index] = RRA;
	}
	if (b_len > 1)
	{
		if (last != SB)
			(*opper)[++index] = SB;
		if (last != RRB)
			(*opper)[++index] = RB;
		if (last != RB)
			(*opper)[++index] = RRB;
	}
	if (b_len > 1 && a_len > 1)
	{
		if (last != SS)
			(*opper)[++index] = SS;
		if (last != RRR)
			(*opper)[++index] = RR;
		if (last != RR)
			(*opper)[++index] = RRR;
	}
	if (b_len > 0 && last != PB)
		(*opper)[++index] = PA;
	if (a_len > 0 && last != PA)
		(*opper)[++index] = PB;
	return (index + 1);
}

static void undo(short *a, short *b, short last, t_index *index)
{
	if (last == SA)
		swap(a, index->a_start);
	else if (last == SB)
		swap(b, index->b_start);
	else if (last == SS)
	{
		swap(a, index->a_start);
		swap(b, index->b_start);
	}
	else if (last == PA)
		push(b, a, &index->b_start, &index->a_start);
	else if (last == PB)
		push(a, b, &index->a_start, &index->b_start);
	else if (last == RA)
		rev_rotate(a, &index->a_start, &index->a_end);
	else if (last == RB)
		rev_rotate(b, &index->b_start, &index->b_end);
	else if (last == RR)
	{
		rev_rotate(a, &index->a_start, &index->a_end);
		rev_rotate(b, &index->b_start, &index->b_end);
	}
	else if (last == RRA)
		rotate(a, &index->a_start, &index->a_end);
	else if (last == RRB)
		rotate(b, &index->b_start, &index->b_end);
	else if (last == RRR)
	{
		rotate(a, &index->a_start, &index->a_end);
		rotate(b, &index->b_start, &index->b_end);
	}
}

void expand(t_node *node, t_index *index)
{
	short i;
	short *untried_actions;
	short random;
	short nb;

	if (!node || !(untried_actions = (short *)malloc(sizeof(short) * 11)))
		return ;
	node->number_of_childen = is_poss(&untried_actions, node->my_action, index->a_end - index->a_start, index->b_end - index->b_start);
	nb = node->number_of_childen;
	
	node->childen = (t_node**)malloc(sizeof(t_node*) * node->number_of_childen);
	i = -1;
	while (++i < node->number_of_childen)
	{
		node->childen[i] = new_node();
		node->childen[i]->parent = node;
		node->childen[i]->childen = NULL;
		node->childen[i]->parent_action = node->my_action;
		random = ((rand() % (nb)));
		node->childen[i]->my_action = untried_actions[random];
		untried_actions[random] = untried_actions[--nb];
		untried_actions[nb] = 0;
		// node->childen[i]->state = get_state_after_my_action(node->childen[i]->my_action);
		node->childen[i]->number_of_visits = 0;
		node->childen[i]->result = 0;
		node->childen[i]->my_value = 0;
		// node->childen[i]->number_of_untriend_actions = get_availabe_actions();
	}
}

void back_propagation(t_node *node, short value, short *a, short *b, t_index *index)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->parent != NULL)
	{
		undo(a, b, tmp->my_action, index);
		tmp->my_value += value;
		tmp->number_of_visits += 1;
		tmp = tmp->parent;
	}
}

double upper_confidence_bounds(short value, short N, short n)
{
	if (value)
		return (value + 2 * sqrt(log(N)/n));
	else
		return (0);
}

short best_ucb(t_node *leaf, short N)
{
	short best;
	short best_id;
	short tmp;
	short i;

	i = -1;
	best = 0;
	while (++i < leaf->number_of_childen)
	{
		tmp = upper_confidence_bounds(leaf->childen[i]->my_value, N, leaf->childen[i]->number_of_visits);
		if (tmp > best && tmp != 0)
		{
			best = tmp;
			best_id = i;
		}
		else if (tmp == 0)
			return (i);
	}
	return (best_id);
}



short roll_out(short *a, short *b, t_index *index)
{
	return (ai(a, b, index));
}

void tree_travesal(short *a, short *b, t_index *index)
{
	t_node	*start;
	t_node	*leaf;
	short	value;
	// short	nb = -1;

	start = start_node();
	print_t_ilists(a, b, index->a_start, index->b_start, index->a_end, index->b_end);
	while (1)
	{
		// ++nb;
		leaf = start;
		while (leaf->childen != NULL)
		{
			leaf = leaf->childen[best_ucb(leaf, start->number_of_visits)];
			corr_ai_op(a, b, leaf->my_action, index);
		}
		// print_t_ilists(a, b, index->a_start, index->b_start, index->a_end, index->b_end);
		expand(leaf, index);
		value = roll_out(a, b, index);
		// printf("%d\n", value);
		back_propagation(leaf, value, a, b, index);
	}
}
