/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:22:44 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/07 18:49:45 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_input(int argc, char **argv, t_stack *stack_a)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->size = 0;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		free_split(argv);
	}
	if (argc > 2)
		validate_input(argc, argv, stack_a);
	return (0);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	validate_input(int argc, char **argv, t_stack *stack_a)
{
	//check for non-integer inputs
	//check for input below INT_MIN and above INT_MAX
	//check for duplicates
	//populate_stack_a();
}

void	wrong_input(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
