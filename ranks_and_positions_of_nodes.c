/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks_and_positions_of_nodes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:12:10 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/15 20:53:22 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	loop from 1st node, if current_node->value < smallest_node_value found so
	far, update its value and itself as smallest, until there's no more nodes */
t_node	*find_smallest_node(t_stack *stack_a)
{
	t_node	*current_node;
	t_node	*smallest_node;
	int		current_smallest_node_value;

	current_node = stack_a->first;
	smallest_node = current_node;
	current_smallest_node_value = current_node->value;
	while (current_node != NULL)
	{
		if (current_node->value < current_smallest_node_value)
		{
			current_smallest_node_value = current_node->value;
			smallest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (smallest_node);
}

/*	exact same logic as find_smallest_node but this function is used in
	assign_ranks_to_nodes(), so if statement also just checks unassigned nodes*/
t_node	*find_biggest_node(t_stack *stack_a)
{
	t_node	*current_node;
	t_node	*biggest_node;
	int		current_biggest_node_value;

	current_node = stack_a->first;
	biggest_node = current_node;
	current_biggest_node_value = INT_MIN;
	while (current_node != NULL)
	{
		if (current_node->value > current_biggest_node_value
			&& current_node->rank == -1)
		{
			current_biggest_node_value = current_node->value;
			biggest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (biggest_node);
}

/* loop from 1st node, if current_node==smallest_node return current_node_pos */
int	find_position_of_smallest_node(t_stack *stack_a)
{
	t_node	*current_node;
	t_node	*smallest_node;
	int		current_node_position;

	current_node = stack_a->first;
	smallest_node = find_smallest_node(stack_a);
	current_node_position = 0;
	while (current_node != NULL)
	{
		if (current_node == smallest_node)
			return (current_node_position);
		current_node = current_node->next;
		current_node_position++;
	}
	return (-1);
}

/* loop all stack_a and assign rank to each node from the biggest_node */
void	assign_ranks_to_nodes(t_stack *stack_a)
{
	t_node	*biggest_node;
	int		current_node_rank;

	current_node_rank = stack_a->size - 1;
	while (current_node_rank >= 0)
	{
		biggest_node = find_biggest_node(stack_a);
		if (biggest_node)
			biggest_node->rank = current_node_rank--;
	}
}

/* find position of the node with the maximum rank in the stack */
int	find_position_of_biggest_node(t_stack *stack)
{
	t_node	*current_node;
	int		current_max_rank;
	int		current_node_position;
	int		biggest_node_position;

	current_node = stack->first;
	current_max_rank = INT_MIN;
	biggest_node_position = 0;
	current_node_position = 0;
	while (current_node)
	{
		if (current_node->rank > current_max_rank)
		{
			current_max_rank = current_node->rank;
			biggest_node_position = current_node_position;
		}
		current_node = current_node->next;
		current_node_position++;
	}
	return (biggest_node_position);
}
