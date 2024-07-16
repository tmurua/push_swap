/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:09 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/16 17:25:31 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort large nbr of elements w/combination of sorting and indexing strategies
1. Assign indexes to elements in stack_a
2. Move elements from stack_a to stack_b in sorted intervals
3. Move elements from stack_b back to stack_a in sorted order
4. Return the sorted stack_a */
t_node	*sort_big(t_node *head_a, t_node *head_b)
{
	assign_indexes(head_a);
	atob_interval(&head_a, &head_b);
	btoa_max(&head_a, &head_b);
	return (head_a);
}

/* Assign indexes to each element in stack_a based on their value.
1. Get the size of stack_a.
2. For each element, find the max unindexed element and assign an index to it
3. Repeat until all elements are indexed. */
void	assign_indexes(t_node *head_a)
{
	int		size_a;
	int		max;
	t_node	*tmp;
	t_node	*max_unindexed;

	size_a = stack_size(head_a);
	while (size_a--)
	{
		tmp = head_a;
		max_unindexed = head_a;
		max = INT_MIN;
		while (tmp)
		{
			if ((tmp->nbr >= max) && (tmp->index == -1))
			{
				max = tmp->nbr;
				max_unindexed = tmp;
			}
			tmp = tmp->next;
		}
		max_unindexed->index = size_a;
	}
}

/* Move elements from stack_a to stack_b in sorted intervals
1. Calculate the size of each interval
2. For each element in stack_a, move it to stack_b if belongs to current interval
3. Adjust the interval size and count as needed
4. If the element belongs to the lower half of the interval, rotate stack_b
5. If the element does not belong to the current interval, rotate stack_a */
void	atob_interval(t_node **head_a, t_node **head_b)
{
	int	size_inter;
	int	count_inter;
	int	i;

	size_inter = (stack_size(*head_a) / 10) + 15;
	count_inter = 1;
	i = 0;
	while (*head_a != NULL)
	{
		if ((*head_a)->index < (count_inter * size_inter))
		{
			pb(head_a, head_b);
			if ((*head_b)->index
				< (count_inter * size_inter) - (size_inter / 2))
				rb(head_b);
			i++;
		}
		else
			ra(head_a);
		if (i == (count_inter * size_inter))
			count_inter++;
	}
}

/* Move elements from stack_b back to stack_a in sorted order
1. Find the position of the maximum index in stack_b.
2. If max index is in 1st half of stack_b, rotate stack_b
until the maximum index is at the top, then push it to stack_a.
3. If max index is in 2nd half of stack_b, reverse rotate stack_b
until the maximum index is at the top, then push it to stack_a.
4. Repeat until all elements are moved from stack_b to stack_a. */
void	btoa_max(t_node **head_a, t_node **head_b)
{
	int	pos_max_index;

	while (*head_b != NULL)
	{
		pos_max_index = position_max_index(*head_b);
		if (pos_max_index <= (stack_size(*head_b) / 2))
		{
			while (pos_max_index--)
				rb(head_b);
			pa(head_b, head_a);
		}
		else
		{
			pos_max_index = stack_size(*head_b) - pos_max_index;
			while (pos_max_index--)
				rrb(head_b);
			pa(head_b, head_a);
		}
	}
}
