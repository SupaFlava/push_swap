/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:08:40 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/14 12:11:30 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
//rotate top node with bottom one

static void rotate(t_stack_node **stack)
{
    t_stack_node *last_node;
    t_stack_node *first_node;

    if (!*stack || !(*stack)->next)
        return(NULL);
    first_node = *stack;
    last_node =find_last(*stack);
    *stack = first_node->next;
    (*stack)->prev = NULL;
    last_node->next = first_node;
    first_node->prev = last_node;
    first_node->next = NULL;
}

void ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
     if(!print)
        ft_printf("rb\n");
}
void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if(!print)
        ft_printf("rr\n");
}