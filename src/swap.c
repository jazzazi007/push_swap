/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:43 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:44 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_node **stack_a, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*stack_a = second;
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_node **stack_b, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*stack_b = second;
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b, bool print)
{
	sa(stack_a, true);
	sb(stack_b, true);
	if (!print)
		ft_printf("ss\n");
}
