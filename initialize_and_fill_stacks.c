/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_and_fill_stacks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:31:13 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/15 13:42:15 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

void	populate_stack_a(int argc, char **argv, t_stack *stack_a)
{
	t_node	*next_node;
	t_node	*previous_node;
	int		i;

	i = 0;
	previous_node = NULL;
	while (argv[i])
	{
		next_node = create_node(ft_atoi(argv[i]), stack_a);
		next_node->previous = previous_node;
		if (previous_node)
			previous_node->next = next_node;
		else
			stack_a->first = next_node;
		previous_node = next_node;
		i++;
	}
	stack_a->last = previous_node;
	stack_a->size = argc;
}

/* assign node->rank to -1 as node is still unassigned */
t_node	*create_node(int value, t_stack *stack_a)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		wrong_input(stack_a);
	node->value = value;
	node->rank = -1;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = stack->first;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	initialize_stack(stack);
}
