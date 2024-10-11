/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:23:21 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/11 20:04:30 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;

	handle_input(argc, argv, &stack_a);
	free_stack(&stack_a);
}

void	free_stack(t_stack *stack_a)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = stack_a->first;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	stack_a->first = NULL;
	stack_a->last = NULL;
	stack_a->size = 0;
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
		swap_a_sa(stack_a);
		ft_printf("stack_a after swap:\n");
		ft_printf("first element: %d\n", stack_a->first->value);
		ft_printf("second element: %d\n", stack_a->first->next->value);
		ft_printf("last element: %d\n", stack_a->last->value);
		ft_printf("size: %d\n", stack_a->size);
	}
	else
		ft_printf("stack_a is empty.\n");
}
*/
