/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:22:44 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/15 21:21:04 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_input(int argc, char **argv, t_stack *stack_a)
{
	if (argc == 1)
		return ;
	if (argc == 2)
		handle_two_arguments(argc, argv, stack_a);
	if (argc > 2)
	{
		argv = argv + 1;
		argc = argc - 1;
		if (check_non_integer_input(argv) == 1 || check_duplicates(argv) == 1
			|| check_underflow_overflow(argv) == 1)
			wrong_input(stack_a);
		populate_stack_a(argc, argv, stack_a);
	}
}

void	handle_two_arguments(int argc, char **argv, t_stack *stack_a)
{
	argv = ft_split(argv[1], ' ');
	argc = count_elements(argv);
	if (check_non_integer_input(argv) == 1 || check_duplicates(argv) == 1
		|| check_underflow_overflow(argv) == 1 || argc == 0)
	{
		free_split(argv);
		wrong_input(stack_a);
	}
	populate_stack_a(argc, argv, stack_a);
	free_split(argv);
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

int	count_elements(char **argv)
{
	int	new_argc;

	new_argc = 0;
	while (argv[new_argc])
		new_argc++;
	return (new_argc);
}

void	wrong_input(t_stack *stack_a)
{
	if (stack_a)
		free_stack(stack_a);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
