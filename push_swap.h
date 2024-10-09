/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:06:02 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/09 11:01:47 by tmurua           ###   ########.fr       */
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
typedef struct s_element
{
	int					value;
	int					index;
	struct s_element	*next;
	struct s_element	*previous;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*bottom;
	int			size;
}	t_stack;


/* function prototypes */
/* input_handler.c */
int		handle_input(int argc, char **argv, t_stack *stack);
void	handle_two_arguments(int argc, char **argv, t_stack *stack);
void	free_split(char **argv);
int		count_elements(char **argv);
void	wrong_input(void);

/* input_validation.c */
int		validate_input(int argc, char **argv, t_stack *stack_a);
int		check_non_integer_input(char **argv);
int		check_underflow_overflow(char **argv);
int		check_duplicates(char **argv);
void	populate_stack_a(int argc, char **argv, t_stack *stack_a);

/* sorting_operations_stack_a.c */

/* sorting_operations_stack_b.c */

/* sorting_operations_both_stacks.c */

#endif
