/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:16:42 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/06 11:13:44 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	current_index(t_s_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_s_node *a, t_s_node *b)
{
	t_s_node	*current_node_b;
	t_s_node	*target_node;
	long		best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_node_b = b;
		while (current_node_b)
		{
			if (current_node_b->nbr < a->nbr
				&& current_node_b->nbr > best_match_index)
			{
				best_match_index = current_node_b->nbr;
				target_node = current_node_b;
			}
			current_node_b = current_node_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	calculate_costs_a_to_b(t_s_node *a, t_s_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_s_node *stack)
{
	t_s_node		*cheapest_node;
	long			cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	update_nodes_a(t_s_node *a, t_s_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	calculate_costs_a_to_b(a, b);
	set_cheapest(a);
}
