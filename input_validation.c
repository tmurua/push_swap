/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/08 13:09:11 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(int argc, char **argv, t_stack *stack_a)
{
	check_non_integer_input(argc, argv);
	check_underflow_overflow(argc, argv);
	check_duplicates(argc, argv);
	populate_stack_a(argc, argv, *stack_a);
	//call wrong_input if any of the above fails
}

int	check_non_integer_input(int argc, char **argv)
{
	// return 0 for success and 1 for failure
}

int	check_underflow_overflow(int argc, char **argv)
{
	//check for input below INT_MIN and above INT_MAX
	// return 0 for success and 1 for failure
}

int	check_duplicates(int argc, char **argv)
{
	// return 0 for success and 1 for failure
}

void	populate_stack_a(int argc, char **argv, t_stack *stack_a)
{

}
