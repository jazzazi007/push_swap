/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:50:50 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:50:54 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_node_index(t_node *stack, int index, int median)
{
	stack->index = index;
	stack->above_median = (index <= median);
}

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_size(stack) / 2;
	while (stack)
	{
		set_node_index(stack, i++, median);
		stack = stack->next;
	}
}

void	set_cheapest(t_node *stack)
{
	t_node	*cheapest;

	cheapest = find_cheapest_node(stack);
	if (cheapest)
		cheapest->cheapest = true;
}

void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
