/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:25:26 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/15 20:53:46 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	assign_ranks_to_nodes(stack_a);
	push_to_b_in_chunks(stack_a, stack_b);
	push_back_to_a_in_order(stack_a, stack_b);
}

/* push nodes from stack a to b in chunks */
void	push_to_b_in_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	current_chunk;

	chunk_size = (stack_a->size / 10) + 15;
	current_chunk = 1;
	while (stack_a->size > 0)
	{
		if (stack_a->first->rank <= current_chunk * chunk_size)
		{
			push_to_b_pb(stack_a, stack_b);
			if (stack_b->first->rank <= (current_chunk * chunk_size)
				- (chunk_size / 2))
				rotate_b_rb(stack_b);
		}
		else
			rotate_a_ra(stack_a);
		if (stack_b->size >= (current_chunk * chunk_size))
			current_chunk++;
	}
}

/*	biggest node goes to top of b, then push all nodes back to a
	check if biggest node  is in 1st or 2nd half to rb or rrb */
void	push_back_to_a_in_order(t_stack *stack_a, t_stack *stack_b)
{
	int	biggest_node_position;

	while (stack_b->size > 0)
	{
		biggest_node_position = find_position_of_biggest_node(stack_b);
		if (biggest_node_position <= stack_b->size / 2)
		{
			while (biggest_node_position > 0)
			{
				rotate_b_rb(stack_b);
				biggest_node_position--;
			}
		}
		else
		{
			biggest_node_position = stack_b->size - biggest_node_position;
			while (biggest_node_position > 0)
			{
				reverse_rotate_b_rrb(stack_b);
				biggest_node_position--;
			}
		}
		push_to_a_pa(stack_b, stack_a);
	}
}
