/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:27:38 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/10 11:02:21 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	append_node(t_s_node **stack, int value)
{
	t_s_node	*new_node;
	t_s_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_s_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = value;
	new_node->cheapest = 0;
	if (!(*stack))
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

t_s_node	*get_cheapest(t_s_node *stack)
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

void	init_stack_a(t_s_node **a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_exit(a);
		number = ft_atol(argv[i], a);
		if (number > LONG_MAX || number < LONG_MIN)
			error_exit(a);
		if (duplicate_error(*a, (int)number))
			error_exit(a);
		append_node(a, (int)number);
		i++;
	}
}

void	align_node_to_top(t_s_node **stack, t_s_node *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
