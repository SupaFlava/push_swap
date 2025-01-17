/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:34:50 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/15 19:25:34 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static  void swap(t_stack_node **head)
{
    if (!head || !(*head)->next)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev =(*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}
void    sa(t_stack_node **a, bool print)
{
    swap(a);
    if (!print)
        printf("sa\n");
}
void    sb(t_stack_node **b, bool print)
{
    swap(b);
    if (!print)
        printf("sb\n");
}
void    ss(t_stack_node **a , t_stack_node **b , bool print)
{
    swap(a);
    swap(b);
    if (!print)
        printf("ss\n");
}