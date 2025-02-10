/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:08:40 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/03 15:37:42 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_s_node **stack)
{
	t_s_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_s_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_s_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_s_node **a, t_s_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
