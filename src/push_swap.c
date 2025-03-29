/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:52:07 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:52:09 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*static void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}*/

static int write_exit()
{
	write(2, "Error\n", 6);
	return (1);
}

static void	handle_small_sort(t_node **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a, false);
	else if (size == 3)
		sort_three(stack_a);
}

static void free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
static void process_input(int argc, char **argv, t_node **stack_a)
{
    char **split_args;
	long num;

    if (argc == 2)
    {
        if (!argv[1][0])
			exit(write_exit());
        if (!ft_strchr(argv[1], ' '))
        {
            if (error_detect_str(argv[1]))
            	exit(write_exit());
            num = ft_atol(argv[1]);
            if (num > INT_MAX || num < INT_MIN)
            	exit(write_exit());
            exit(0);
        }
        split_args = ft_split(argv[1], ' ');
        if (!split_args)
        	exit(write_exit());
        init_a(stack_a, split_args);
        free_args(split_args);
    }
	else
        init_a(stack_a, argv + 1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	process_input(argc, argv, &stack_a);
	if (!stack_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 3)
			handle_small_sort(&stack_a);
		else if (stack_size(stack_a) ==4)
			sort_four(&stack_a, &stack_b);
		else if (stack_size(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	//print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}
