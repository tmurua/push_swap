/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/09 09:55:48 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_input(int argc, char **argv, t_stack *stack_a)
{
	(void) stack_a;
	(void) argc;
	(void) argv;
	//check_underflow_overflow(argc, argv);
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

int	check_duplicates(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[i])
	{
		y = i + 1;
		while (argv[y])
		{
			if (!ft_strncmp(argv[i], argv[y], ft_strlen(argv[i])))
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

/* this function needs to user integers instead of strings
int	check_underflow_overflow(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[i])
	{
		if (argv[i][y] >= '-2147483648' && argv[i][y] <= '2147483647')
			while (argv[i][y] >= '-2147483648' && argv[i][y] <= '2147483647')
				y++;
		else
			return (1);
		i++;
	}
	return (0);
} */
/*
void	populate_stack_a(int argc, char **argv, t_stack *stack_a)
{

}
*/
