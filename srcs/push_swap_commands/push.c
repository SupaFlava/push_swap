/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:35 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/03 15:37:42 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_s_node **dest, t_s_node **src)
{
	t_s_node	*to_push;

	if (!*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (!*dest)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pa(t_s_node **a, t_s_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_s_node **b, t_s_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
