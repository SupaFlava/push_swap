/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:16:51 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/30 16:13:48 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void rotate_both(t_stack_node **a,t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node 
		&& *a != cheap)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rt_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->above_median 
		&& cheap->target_node->above_median)
		rotate_both(a, b, cheap);
	else if (!(cheap->above_median)
		&& !(cheap->target_node->above_median))
		rev_rt_both(a, b, cheap);
	prep_for_push(a, cheap, 'a');
	prep_for_push(b, cheap->target_node, 'b');
	pb(b, a, false);
}


static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a,false);
		else
			rra(a,false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int length_a;

	length_a = stack_len(*a);
	if (length_a-- > 3  && !is_sorted(*a))
		pb(b, a, false);
	if (length_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (length_a-- > 3 && !is_sorted(*a))
	{
		initialize_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b ,false);
	}
	current_index(*a);
	min_on_top(a);
}
