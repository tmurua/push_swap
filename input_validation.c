/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/08 23:51:47 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(int argc, char **argv, t_stack *stack_a)
{
	(void) stack_a;
	(void) argc;
	(void) argv;
	//check_underflow_overflow(argc, argv);
	//check_duplicates(argc, argv);
	//populate_stack_a(argc, argv, *stack_a);
	//call wrong_input if any of the above fails
	return (0);
}

int	check_non_integer_input(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[i])
	{
		y = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			y++;
		if (argv[i][y] >= '0' && argv[i][y] <= '9')
			while (argv[i][y] >= '0' && argv[i][y] <= '9')
				y++;
		else
			return (1);
		i++;
	}
	return (0);
}
/*
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
*/
