/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:15:23 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/17 11:57:31 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
// to include 
typedef struct s_stack_node
{
    int nbr;
    int index;
    int push_coast;
    bool    above_median;
    bool    cheapest;
    struct  s_stack_node  *target_node;
    struct  s_stack_node   *next;
    struct  s_stack_node    *prev;
} t_stack_node;

int				syntax_error(char *string); 
int				duplicate_error(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_error(t_stack_node **a);

void			init_stack_a(t_stack_node **a, char **argv); 
char			**split(char *s, char c);

void			initialize_nodes_a(t_stack_node *a, t_stack_node *b); 
void			init_nodes_b(t_stack_node *a, t_stack_node *b); 
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
void			sort_three(t_stack_node **a);
void    sort_stacks(t_stack_node **a, t_stack_node **b);


int				stack_len(t_stack_node *stack); 
t_stack_node	*find_last(t_stack_node *stack); 
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack); 
t_stack_node	*find_max(t_stack_node *stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

t_stack_node *find_min(t_stack_node *stack);

#endif