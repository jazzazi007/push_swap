/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:28 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:30 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_node **stack_a, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = find_last(*stack_a);
	*stack_a = first->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	(*stack_a)->prev = NULL;
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node **stack_b, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = find_last(*stack_b);
	*stack_b = first->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	(*stack_b)->prev = NULL;
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b, bool print)
{
	ra(stack_a, true);
	rb(stack_b, true);
	if (!print)
		ft_printf("rr\n");
}
