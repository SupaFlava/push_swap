/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:33:41 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/06 21:47:38 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h";
void    init_stack_a(t_stack_node **a, char **argv)
{
    long    n;
    int     i;
    i = 0;
    while(argv[i])
    {
        //if error  handle error
        n = ft_atoi(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            // FREE ERRRORS
        
    }
}