/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:51:45 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:51:46 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = NULL;
	new->cheapest = 0;
	return (new);
}

static void	append_node(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tail;

	if (!stack)
		return ;
	new = create_node(value);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
	new->prev = tail;
}

void	init_a(t_node **a, char **argv)
{
	long	num;

	while (*argv)
	{
		if (error_detect_str(*argv))
			free_errors(a);
		num = ft_atol(*argv);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(a);
		if (num_duplicate(*a, (int)num))
			free_errors(a);
		append_node(a, (int)num);
		argv++;
	}
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
