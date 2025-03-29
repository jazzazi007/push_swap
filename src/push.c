/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:20 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:21 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*push_node;

	if (!*stack_b)
		return ;
	push_node = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	push_node->prev = NULL;
	if (!*stack_a)
	{
		*stack_a = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack_a;
		push_node->next->prev = push_node;
		*stack_a = push_node;
	}
	ft_printf("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	t_node	*push_node;

	if (!*stack_a)
		return ;
	push_node = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	push_node->prev = NULL;
	if (!*stack_b)
	{
		*stack_b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack_b;
		push_node->next->prev = push_node;
		*stack_b = push_node;
	}
	ft_printf("pb\n");
}
