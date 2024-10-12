/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:06:02 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/12 12:10:28 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* macros*/
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/* structures */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	int		size;
}	t_stack;

/* function prototypes */
/* main */
void	free_stack(t_stack *stack);
void	printing_tests(t_stack *stack_a);

/* input_handler.c */
int		handle_input(int argc, char **argv, t_stack *stack_a);
void	handle_two_arguments(int argc, char **argv, t_stack *stack_a);
void	free_split(char **argv);
int		count_elements(char **argv);
void	wrong_input(t_stack *stack_a);

/* input_validation.c */
int		check_non_integer_input(char **argv);
int		check_underflow_overflow(char **argv);
int		check_duplicates(char **argv);
void	populate_stack_a(int argc, char **argv, t_stack *stack_a);
t_node	*create_node(int value, int index, t_stack *stack_a);

/* sorting_operation_swap.c */
void	swap(t_stack *stack);
void	swap_first_two_nodes(t_stack *stack, t_node *og_first, t_node *second);
void	swap_a_sa(t_stack *stack_a);
void	swap_b_sb(t_stack *stack_b);
void	swap_swap_ss(t_stack *stack_a, t_stack *stack_b);

/* sorting_operation_rotate.c */
void	rotate(t_stack *stack);
void	rotate_first_to_last(t_stack *stack, t_node *og_first, t_node *og_last);
void	rotate_a_ra(t_stack *stack_a);
void	rotate_b_rb(t_stack *stack_b);
void	rotate_rotate_rr(t_stack *stack_a, t_stack *stack_b);

/* sorting_operation_reverse_rotate.c */
void	reverse_rotate(t_stack *stack);
void	revers_last_to_first(t_stack *stack, t_node *og_last, t_node *og_first);
void	reverse_rotate_a_rra(t_stack *stack_a);
void	reverse_rotate_b_rrb(t_stack *stack_b);
void	reverse_rotate_rotate_rrr(t_stack *stack_a, t_stack *stack_b);

/* sorting_operation_push.c */

#endif
