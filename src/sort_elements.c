/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:36 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:37 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stacks(t_node **a, t_node **b)
{
	int	len;

	len = stack_size(*a);
	if (--len > 3 && !stack_sorted(*a))
		pb(b, a);
	if (--len > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	sort_three(t_node **stack)
{
	t_node	*max;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	max = find_max(*stack);
	if (max == *stack)
		ra(stack, false);
	else if ((*stack)->next == max)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}

void sort_four(t_node **stack_a, t_node **stack_b)
{
    t_node *min;
    
    min = find_min(*stack_a);
    while (*stack_a != min)
    {
        if (min->above_median)
            ra(stack_a, false);
        else
            rra(stack_a, false);
    }
    pb(stack_b, stack_a);
    sort_three(stack_a);
    pa(stack_a, stack_b);
}
void sort_five(t_node **stack_a, t_node **stack_b)
{
    t_node *min;
    
    while (stack_size(*stack_a) > 3)
    {
        min = find_min(*stack_a);

        while (*stack_a != min)
        {
            if (min->above_median)
                ra(stack_a, false);
            else
                rra(stack_a, false);
        }
        pb(stack_b, stack_a);
    }
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}