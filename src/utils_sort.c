/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:15:47 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/25 16:15:49 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_node **a)
{
	t_node	*min;

	min = find_min(*a);
	while ((*a)->nbr != min->nbr)
	{
		if (min->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
