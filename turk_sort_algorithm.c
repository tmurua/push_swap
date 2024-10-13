/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:25:26 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/13 21:57:43 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_all_nodes_to_b(stack_a, stack_b);
	push_all_nodes_to_a(stack_b, stack_a);
}

/* repeatedly find smallest node in stack_a, move to top, push to stack_b */
void	push_all_nodes_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest_node_position;

	while (stack_a->size > 0)
	{
		smallest_node_position = find_position_of_smallest_node(stack_a,
				stack_a->first);
		move_smallest_node_to_top(stack_a, smallest_node_position);
		push_to_b_pb(stack_a, stack_b);
	}
}

void	push_all_nodes_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		push_to_a_pa(stack_b, stack_a);
	}
}

/*	loop from first node, if current_node->value < smallest found so far, update
	its value and position to be the smallest, until there's no more nodes */
int	find_position_of_smallest_node(t_stack *stack_a, t_node *current_node)
{
	int	current_smallest_node_value;
	int	smallest_node_position;
	int	node_position;

	current_smallest_node_value = current_node->value;
	smallest_node_position = 0;
	node_position = 0;
	while (current_node != NULL)
	{
		if (current_node->value < current_smallest_node_value)
		{
			current_smallest_node_value = current_node->value;
			smallest_node_position = node_position;
		}
		current_node = current_node->next;
		node_position++;
	}
	return (smallest_node_position);
}

/*	if smallest node is in the first half rotate stack until it is at the top
	if it is in the second half, reverse rotate stack until it is at the top */
void	move_smallest_node_to_top(t_stack *stack_a, int smallest_node_position)
{
	if (smallest_node_position <= stack_a->size / 2)
	{
		while (smallest_node_position > 0)
		{
			rotate_a_ra(stack_a);
			smallest_node_position--;
		}
	}
	else
	{
		smallest_node_position = stack_a->size - smallest_node_position;
		while (smallest_node_position > 0)
		{
			reverse_rotate_a_rra(stack_a);
			smallest_node_position--;
		}
	}
}
