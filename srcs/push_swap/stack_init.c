/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:27:38 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/19 13:31:27 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static  long ft_atol(const char *s)
{
    long    result;
    int     sign;
    result = 0;
    
    sign = 1;
    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\v') 
        s++;
    
     if (*s == '-' || *s == '+')
        {
            if (*s == '-')
                sign = -1;
            s++;
        }
    while(ft_isdigit(*s))
	{
        result = result * 10 + (*s - '0');
		s++;
	}
    return (result * sign);
}

static void append_node(t_stack_node **stack, int value)
{
    t_stack_node *new_node;
    t_stack_node *last_node;
    if(!stack)
        return;
    new_node = malloc(sizeof(t_stack_node));
    if (!new_node)
        return ;
    new_node->nbr = value;
    new_node->cheapest = 0;
    new_node->next = NULL;
    if(!(*stack))
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last_node = find_last(*stack);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
    
}
t_stack_node *get_cheapest(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void    init_stack_a(t_stack_node **a, char **argv)
{
    long    number;
    int     i;

    i = 0;
    while(argv[i])
    {
        if (syntax_error(argv[i]))
			free_error(a);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number <  INT_MIN)
			free_error(a);
		if (duplicate_error(*a, (int)number))
			free_error(a);
		append_node(a, (int)number);
		i++; 
    }
}

void    prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if(top_node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }
}