/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:16:51 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/14 15:14:18 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int length_a;
    length_a = stack_len(*a);
    if (length_a-- > 3 && !stack_sorted(*a))
        pb(b, a , false);
    if (length_a-- > 3 && !stack_sorted(*a))
        pb(b, a , false);
    while(length_a-- > 3 && !stack_sorted(*a))
    {
        initiate_nodes_a();
    }
    
}
