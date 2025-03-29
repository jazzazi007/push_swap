/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:25:57 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/25 16:25:59 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_best_target(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;
	t_node	*target;
	long	best_value;

	best_value = LONG_MIN;
	target = NULL;
	current = stack_b;
	while (current)
	{
		if (current->nbr < stack_a->nbr && current->nbr > best_value)
		{
			best_value = current->nbr;
			target = current;
		}
		current = current->next;
	}
	if (!target)
		return (find_max(stack_b));
	return (target);
}

void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	while (stack_a)
	{
		stack_a->target_node = find_best_target(stack_a, stack_b);
		stack_a = stack_a->next;
	}
}

void	calculate_push_cost(t_node *node, int len_a, int len_b)
{
	node->push_cost = node->index;
	if (!node->above_median)
		node->push_cost = len_a - node->index;
	if (node->target_node->above_median)
		node->push_cost += node->target_node->index;
	else
		node->push_cost += len_b - node->target_node->index;
}

void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	while (stack_a)
	{
		calculate_push_cost(stack_a, len_a, len_b);
		stack_a = stack_a->next;
	}
}

t_node	*find_cheapest_node(t_node *stack)
{
	t_node	*cheapest;
	long	min_cost;

	if (!stack)
		return (NULL);
	min_cost = LONG_MAX;
	cheapest = NULL;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
