/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:51:52 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:51:56 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_node **stack_a, bool print)
{
	t_node	*temp;
	t_node	*current;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	current = *stack_a;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *stack_a;
	temp->prev = NULL;
	(*stack_a)->prev = temp;
	*stack_a = temp;
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **stack_b, bool print)
{
	t_node	*temp;
	t_node	*current;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	current = *stack_b;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = *stack_b;
	temp->prev = NULL;
	(*stack_b)->prev = temp;
	*stack_b = temp;
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b, bool print)
{
	rra(stack_a, true);
	rrb(stack_b, true);
	if (!print)
		ft_printf("rrr\n");
}
