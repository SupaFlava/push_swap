/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:12:03 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/14 12:16:24 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    sort_three(t_stack_node **a)
{
    t_stack_node *biggest;
    
    biggest = find_max(*a);
    if (biggest == *a)
        ra(a,false);
    else if(biggest == (*a)->next)
        rra(a, false);
}