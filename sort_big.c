/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:09 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/19 16:04:19 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts lists with more than 5 numbers. */
t_node	*sort_big(t_node *head_a, t_node *head_b)
{
	assign_indexes(head_a);
	atob_interval(&head_a, &head_b);
	btoa_max(&head_a, &head_b);
	return (head_a);
}

/* Assigns indexes to numbers in the list,
ensuring the node with the highest numbers gets an index of stack size - 1,
and the node with the lowest number gets an index of 0.
Each node's index was initialized to -1 in the add_node function.*/
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

/* Pushes nodes from stack A to stack B
if their indexes are within the determined intervals (inter).
By performing a monte-carlo-like simulation the best interval size was
determined to be 1/10th of the stack size plus 15. Adapt the
interval size to your implementation.
Nodes with indexes falling within the current interval
are moved to stack B.
Additionally (see in-line comment) if their index is smaller than the
middle of the interval, they are placed at the bottom of stack B. */
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

/* Pushes the maximum element from stack B to stack A based on assigned indexes.
If the highest indexes (and thereby number's) position is less than or
equal to half of stack B's size meaning the node is in the upper half
of the stack), it is rotated to the top and then pushed to stack A;
otherwise it is rotated to the bottom and then pushed to stack A. */
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
