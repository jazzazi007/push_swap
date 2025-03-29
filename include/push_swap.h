/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:48:24 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:48:28 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42_libft/libft.h"
# include "../42_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
}					t_stack;

int					error_detect_str(char *str_n);
int					num_duplicate(t_node *a, int n);
void				free_stack(t_node **stack);
void				free_errors(t_node **a);
void				init_a(t_node **a, char **argv);
char				**ft_split(const char *s, char c);
int					stack_size(t_node *stack);
t_node				*find_last(t_node *stack);
bool				stack_sorted(t_node *stack);
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);
void				init_nodes_a(t_node *a, t_node *b);
void				init_nodes_b(t_node *a, t_node *b);
void				current_index(t_node *stack);
void				set_cheapest(t_node *stack);
t_node				*get_cheapest(t_node *stack);
void				prep_for_push(t_node **s, t_node *n, char c);
void				sa(t_node **stack_a, bool print);
void				sb(t_node **b, bool print);
void				ss(t_node **a, t_node **b, bool print);
void				ra(t_node **a, bool print);
void				rb(t_node **b, bool print);
void				rr(t_node **a, t_node **b, bool print);
void				rra(t_node **a, bool print);
void				rrb(t_node **b, bool print);
void				rrr(t_node **a, t_node **b, bool print);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);
void				rotate_both(t_node **a, t_node **b, t_node *cheapest);
void				rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void				move_a_to_b(t_node **a, t_node **b);
void				move_b_to_a(t_node **a, t_node **b);
void				min_on_top(t_node **a);
void				sort_three(t_node **a);
void				sort_stacks(t_node **a, t_node **b);
t_node				*find_best_target(t_node *stack_a, t_node *stack_b);
void				set_target_a(t_node *stack_a, t_node *stack_b);
void				calculate_push_cost(t_node *node, int len_a, int len_b);
void				cost_analysis_a(t_node *stack_a, t_node *stack_b);
t_node				*find_cheapest_node(t_node *stack);
void				set_node_index(t_node *stack, int index, int median);
long				ft_atol(const char *s);
void    sort_four(t_node **stack_a, t_node **stack_b);
void sort_five(t_node **stack_a, t_node **stack_b);

#endif
