/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:23:21 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/07 15:52:49 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	handle_input(argc, **argv, &stack_a);
}

int	handle_input(int argc, char **argv, t_stack *stack_a)
{
	stack_a = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (argc > 2)
		validate_input();
}

int	validate_input(int argc, char **argv, t_stack *stack_a)
{

}

void	wrong_input(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
