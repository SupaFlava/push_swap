/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:27:38 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/13 21:47:06 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


static void append_node(t_stack_node **stack, int n)
{
    t_stack_node *node;
    t_stack_node *last_node;
    if(!stack)
        return;
    node =malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->nbr = n;
    node->cheapest = 0;
    if(!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
    
}
void    init_stack_a(t_stack_node **a, char **argv)
{
    long    number;
    int     i;

    i = 0;
    while(argv[i])
    {
        if (!argv[i]) // implement error and free
        return (-1);

        number = ft_atol(argv[i]);
        if (number > INT_MAX || number < INT_MIN)
            return(a);
        append_node(a, (int) number);
        i++;
            
    }
    
}