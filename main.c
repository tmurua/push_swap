/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:23:21 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/14 20:44:55 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	initialize_stack(&stack_a);
	initialize_stack(&stack_b);
	handle_input(argc, argv, &stack_a);
	check_which_algorithm_to_use(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
