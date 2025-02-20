/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:34:50 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/03 15:37:42 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_s_node **head)
{
	if (!head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_s_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_s_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_s_node **a, t_s_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
