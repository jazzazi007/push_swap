/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:52 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:54 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;
	long	min_val;

	if (!stack)
		return (NULL);
	min_val = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->nbr < min_val)
		{
			min_val = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;
	long	max_val;

	if (!stack)
		return (NULL);
	max_val = LONG_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->nbr > max_val)
		{
			max_val = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
