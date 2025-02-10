/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:16:51 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/10 11:09:34 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both_up(t_s_node **a, t_s_node **b, t_s_node *cheap)
{
	while (*b != cheap->target_node
		&& *a != cheap)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rt_both(t_s_node **a, t_s_node **b, t_s_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	push_cheapest_to_b(t_s_node **a, t_s_node **b)
{
	t_s_node	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->above_median
		&& cheap->target_node->above_median)
		rotate_both_up(a, b, cheap);
	else if (!(cheap->above_median)
		&& !(cheap->target_node->above_median))
		rev_rt_both(a, b, cheap);
	align_node_to_top(a, cheap, 'a');
	align_node_to_top(b, cheap->target_node, 'b');
	pb(b, a);
}

static void	rotate_min_to_top(t_s_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_s_node **a, t_s_node **b)
{
	int	length_a;

	length_a = stack_len(*a);
	if (length_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (length_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (length_a-- > 3 && !is_sorted(*a))
	{
		update_nodes_a(*a, *b);
		push_cheapest_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		update_nodes_b(*a, *b);
		align_node_to_top(a, (*b)->target_node, 'a');
		pa(a, b);
	}
	current_index(*a);
	rotate_min_to_top(a);
}
