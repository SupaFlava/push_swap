/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:15:23 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/13 21:23:13 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
// to include 
typedef struct s_stack_node
{
    int nbr;
    int index;
    int push_coast;
    bool    abode_median;
    bool    cheapest;
    struct  s_stack_node  *target_node;
    struct  s_stack_node   *next;
    struct  s_stack_node    *prev;
} t_stack_node;

// stack initiation

// nodes init

//stack utils

//commands 
// algorithmes
#endif