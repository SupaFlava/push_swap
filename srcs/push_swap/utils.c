/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:25:12 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/15 15:31:22 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool    is_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    { 
        if (stack->nbr > stack->next->nbr)
            return(false);
        stack = stack->next;
    }
        return (true);
}
int stack_len(t_stack_node *stack)
{
    int i;
     if (!stack)
        return(NULL);   
    i = 0;
    while(stack->next)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}
t_stack_node    *find_max(t_stack_node *stack)
{
    long    max_num;
    t_stack_node    *max_node;
    
    if(!stack)
        return(NULL);
    max_num = LONG_MIN;
    while (stack)
    {
     if (stack->nbr > max_num)
     {
        max_num = stack->nbr;
        max_node = stack;
     }   
     stack = stack->next;
    }
    return (max_node);
}
t_stack_node *find_last(t_stack_node *stack)
{
    if (!stack)
        return;
    while(stack->next)
        stack = stack->next;
    return (stack);
}
t_stack_node *find_min(t_stack_node *stack)
{
    long    min;
    t_stack_node *min_node;
    
    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}