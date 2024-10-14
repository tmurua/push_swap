/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorting_algorithms.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:19:31 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/14 12:34:23 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	permutation of 3: 3!=3*2*1=6 (1, 2, 3 is sorted, so 5 left permutations)
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
