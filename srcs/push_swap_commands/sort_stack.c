/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:16:51 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/17 16:12:26 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
static  void rotate_both(t_stack_node **a,t_stack_node **b, t_stack_node *cheapest_node )
{
    while (*b != cheapest_node->target_node 
        && *a != cheapest_node)
        rr(a, b, false);
    current_index(*a);
    current_index(*b);    
}
static void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while(*b != cheapest_node->target_node && *a != cheapest_node)
    rrr(a, b, false);
    current_index(*a);
    current_index(*b);
        
}
static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;
    
    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median 
        && cheapest_node->target_node->above_median)
        rotate_both(a,b, cheapest_node);
    else if (!(cheapest_node->above_median)
            && !cheapest_node->target_node->above_median)
            rev_rotate_both(a, b, cheapest_node);
        prep_for_push(a, cheapest_node, 'a');
        prep_for_push(b, cheapest_node->target_node, 'b');
        pb(b, a, false);
}
static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b ,false);
}
static void min_on_top(t_stack_node **a)
{
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if(find_min(*a)->above_median)
                ra(a,false);
            else
                rra(a,false);
    }
}

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int length_a;
    length_a = stack_len(*a);
    while (length_a-- > 3 && *a && !is_sorted(*a)) {
        pb(b, a, false);
    }

    // Process a and b
    while (length_a-- > 3 && *a && !is_sorted(*a)) {
        initialize_nodes_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a,b);
    }
    current_index(*a);
    min_on_top(a);
}
