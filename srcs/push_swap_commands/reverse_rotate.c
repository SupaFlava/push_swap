/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:43:12 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/15 19:27:37 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void rev_rotate(t_stack_node **stack)
{
    t_stack_node *last_node;

    if(!*stack || !(*stack)->next)
        return;
    last_node = find_last(*stack);
    last_node->prev->next = NULL; // 9bal le5ra
    last_node->next = *stack;
    last_node->prev = NULL;
    *stack = last_node;
    last_node->next->prev = last_node;
}
void    rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (!print)
        printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
        if(!print)
            printf("rrb\n");
}
void    rrr(t_stack_node **a,t_stack_node **b,bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        printf("rrr\n");
}