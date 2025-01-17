/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:39:30 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/15 19:25:34 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int syntax_error(char *string)
{
    if (!(*string == '+'
            || *string == "-" 
            || (*string >= '0' && *string <= '9')))
        return (1);
    if ((*string == '+'|| *string == '-') && !(string[1] >= '0' && string[1] <='9'))
        return (1);
    while (*++string)
    {
        if (!(*string >= '0' && *string <= '9'))
            return (1);
    }
    return (0);
}

int duplicate_error(t_stack_node *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);    
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node *temp;
    t_stack_node *current;
    
    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        temp = current->next;
        current->nbr = 0;
        free(current);
        current = temp;
    }
    *stack = NULL;
}
void free_error(t_stack_node **a)
{
    free_stack(a);
    printf("error\n");
    exit(1);
}
