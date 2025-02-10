/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:15:23 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/10 12:24:29 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_s_node;

int				syntax_error(char *string);
int				duplicate_error(t_s_node *a, int n);
void			free_stack(t_s_node **stack);
void			error_exit(t_s_node **a);
void			free_args(char **argv);
void			init_stack_a(t_s_node **a, char **argv);

void			update_nodes_a(t_s_node *a, t_s_node *b);
void			update_nodes_b(t_s_node *a, t_s_node *b);
void			current_index(t_s_node *stack);
void			set_cheapest(t_s_node *stack);
t_s_node		*get_cheapest(t_s_node *stack);
void			align_node_to_top(t_s_node **s, t_s_node *n, char c);
void			sort_three(t_s_node **a);
void			sort_stacks(t_s_node **a, t_s_node **b);
long			ft_atol(const char *s, t_s_node **a);
int				stack_len(t_s_node *stack);
t_s_node		*find_last(t_s_node *stack);
bool			is_sorted(t_s_node *stack);
t_s_node		*find_min(t_s_node *stack);
t_s_node		*find_max(t_s_node *stack);
void			sa(t_s_node **a);
void			sb(t_s_node **b);
void			ss(t_s_node **a, t_s_node **b);
void			ra(t_s_node **a);
void			rb(t_s_node **b);
void			rr(t_s_node **a, t_s_node **b);
void			rra(t_s_node **a);
void			rrb(t_s_node **b);
void			rrr(t_s_node **a, t_s_node **b);
void			pa(t_s_node **a, t_s_node **b);
void			pb(t_s_node **b, t_s_node **a);
t_s_node		*find_min(t_s_node *stack);

#endif