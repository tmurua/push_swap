/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorting_algorithms.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:19:31 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/14 19:02:43 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	permutation of 3: 3!=3*2*1=6 (1, 2, 3 is sorted, so 5 permutations left)
	1: 3 > 2 > 1: swap 2 top nodes, then reverse rotate 3rd node to top
	2: 1 < 3 > 2: swap 2 top nodes, then rotate 1st node to bottom
	3: 2 > 1 < 3: swap 2 top nodes
	4: 2 < 3 > 1: reverse rotate 3rd node to top
	5: 3 > 1 < 2: rotate 1st node to bottom */
void	sort_stack_with_3_nodes(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->first->value;
	second = stack_a->first->next->value;
	third = stack_a->last->value;
	if (first > second && second > third)
	{
		swap_a_sa(stack_a);
		reverse_rotate_a_rra(stack_a);
	}
	else if (first < second && second > third && third > first)
	{
		swap_a_sa(stack_a);
		rotate_a_ra(stack_a);
	}
	else if (first > second && second < third && third > first)
		swap_a_sa(stack_a);
	else if (first < second && second > third && third < first)
		reverse_rotate_a_rra(stack_a);
	else if (first > second && second < third && third < first)
		rotate_a_ra(stack_a);
}

/* push smallest node to b, sort 3 nodes left, push smallest node back to a */
void	sort_stack_with_4_nodes(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest_node_position;

	smallest_node_position = find_position_of_smallest_node(stack_a);
	move_smallest_node_to_top(stack_a, smallest_node_position);
	push_to_b_pb(stack_a, stack_b);
	sort_stack_with_3_nodes(stack_a);
	push_to_a_pa(stack_b, stack_a);
}

/* push smallest node to b, sort 4 nodes left, push smallest node back to a */
void	sort_stack_with_5_nodes(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest_node_position;

	smallest_node_position = find_position_of_smallest_node(stack_a);
	move_smallest_node_to_top(stack_a, smallest_node_position);
	push_to_b_pb(stack_a, stack_b);
	sort_stack_with_4_nodes(stack_a, stack_b);
	push_to_a_pa(stack_b, stack_a);
}

/*	loop from first node, if current_node->value < smallest found so far, update
	its value and position to be the smallest, until there's no more nodes */
int	find_position_of_smallest_node(t_stack *stack_a)
{
	t_node	*current_node;
	int		current_smallest_node_value;
	int		smallest_node_position;
	int		node_position;

	current_node = stack_a->first;
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
	if it is in the second half, calculate nbr of reverse rotations needed
	then reverse rotate stack until it is at the top */
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
