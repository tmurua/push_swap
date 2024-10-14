/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:23:21 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/14 11:01:24 by tmurua           ###   ########.fr       */
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

/*
void	printing_tests(t_stack *stack_a)
{
	if (stack_a->first && stack_a->last && stack_a->size)
	{
		ft_printf("stack_a:\nfirst element: %d\n", stack_a->first->value);
		ft_printf("second element: %d\n", stack_a->first->next->value);
		ft_printf("last element: %d\n", stack_a->last->value);
		ft_printf("size: %d\n", stack_a->size);
		rotate_a_ra(stack_a);
		ft_printf("stack_a after rotate:\n");
		ft_printf("first element: %d\n", stack_a->first->value);
		ft_printf("second element: %d\n", stack_a->first->next->value);
		ft_printf("last element: %d\n", stack_a->last->value);
		ft_printf("size: %d\n", stack_a->size);
	}
	else
		ft_printf("stack_a is empty.\n");
}
*/
