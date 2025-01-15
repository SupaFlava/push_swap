/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:16:42 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/15 10:16:03 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    current_index(t_stack_node *stack)
{
    int i;
    int median;
    
    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->abode_median = true;
        else
            stack->abode_median = false;
        stack = stack->next;
        i++;
    }
    
}
static void set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current_node_b;
    t_stack_node *target_node;
    long    best_match_index;
    while(a)
    {
        best_match_index = LONG_MIN;
        current_node_b = b;
        while (current_node_b)
        {
            if(current_node_b->nbr < a->nbr 
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
static void cost_analysis(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;
    
    len_a = stack_len(a);
    len_b = stack_len(b);
    
    while (a)
    {
        a->push_coast = a->index;
        if(!(a->abode_median))
            a->push_coast = len_a - (a->index);
        if (a->target_node->abode_median)
            a->push_coast += a->target_node->index;
        else
            a->push_coast += len_b - (a->target_node->index);
        a = a->next;
    }
}
void initiate_nodes_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    const_analysis_a(a,b);
}