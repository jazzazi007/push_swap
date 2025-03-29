/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:51:01 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:51:03 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;
	t_node	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current = stack_a;
		while (current)
		{
			if (current->nbr > stack_b->nbr && current->nbr < best_match_index)
			{
				best_match_index = current->nbr;
				target_node = current;
			}
			current = current->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

void	prep_for_push(t_node **stack, t_node *target, char stack_id)
{
	bool	is_stack_a;

	if (!stack || !*stack || !target)
		return ;
	is_stack_a = (stack_id == 'a');
	while (*stack != target)
	{
		if (target->above_median)
		{
			if (is_stack_a)
				ra(stack, false);
			else
				rb(stack, false);
		}
		else
		{
			if (is_stack_a)
				rra(stack, false);
			else
				rrb(stack, false);
		}
	}
}
