/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorting_algorithms.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:19:31 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/14 13:35:13 by tmurua           ###   ########.fr       */
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
