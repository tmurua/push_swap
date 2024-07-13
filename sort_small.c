/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:18 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/13 03:16:19 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts two numbers in ascending order.
1. Check if the first (current) number is greater than the second (next) number
2. If true, perform the 'sa' (swap) operation to swap the two numbers.
3. Return the head of the sorted stack. */
t_node	*sort_2(t_node *head_a)
{
	if (head_a->nbr > head_a->next->nbr)
		sa(&head_a);
	return (head_a);
}

/* Sorts three numbers in ascending order
1. Assign the values of the three nodes to variables a, b, and c
2. Conditionals to determine order of nbrs and apply the appropriate operations
Case 1: a < b > c > a: Swap the first two elements and then rotate the stack
Case 2: a > b < c > a: Swap the first two elements
Case 3: a < b > c < a: Reverse rotate the stack
Case 4: a > b < c < a: Rotate the stack
Case 5: a > b > c: Swap the first two elements, then reverse rotate the stack
3. Return the sorted stack. */
t_node	*sort_3(t_node *head_a)
{
	int	a;
	int	b;
	int	c;

	a = head_a->nbr;
	b = head_a->next->nbr;
	c = head_a->next->next->nbr;
	if (a < b && b > c && a < c)
	{
		sa(&head_a);
		ra(&head_a);
	}
	else if (a > b && b < c && a < c)
		sa(&head_a);
	else if (a < b && b > c && a > c)
		rra(&head_a);
	else if (a > b && b < c && a > c)
		ra(&head_a);
	else if (a > b && b > c && a > c)
	{
		sa(&head_a);
		rra(&head_a);
	}
	return (head_a);
}

/* Sorts four numbers in ascending order.
1. Perform two iterations to move the smallest two numbers to stack_b
2. Find the position of the minimum number in stack_a and move it to the top
3. Push the top element of stack_a to stack_b
4. Sort the remaining two numbers in stack_a using sort_2
5. Push the two smallest numbers back from stack_b to stack_a
6. Return the sorted stack. */
t_node	*sort_4(t_node *head_a, t_node *head_b)
{
	int	i;
	int	min_pos;

	i = 2;
	while (i--)
	{
		min_pos = position_min_nbr(head_a);
		if (min_pos == 1)
			ra(&head_a);
		if (min_pos == 2)
		{
			ra(&head_a);
			ra(&head_a);
		}
		if (min_pos == 3)
			rra(&head_a);
		pb(&head_a, &head_b);
	}
	head_a = sort_2(head_a);
	pa(&head_b, &head_a);
	pa(&head_b, &head_a);
	return (head_a);
}

/* Sorts five numbers in ascending order.
1. Find the position of the minimum number in stack_a and move it to the top.
2. Push the top element of stack_a to stack_b.
3. Repeat steps 1 and 2 for the second smallest number.
4. Sort the remaining three numbers in stack_a using sort_3.
5. Push the two smallest numbers back from stack_b to stack_a.
6. Return the sorted stack. */
t_node	*sort_5(t_node *head_a, t_node *head_b)
{
	int	min_pos;

	min_pos = position_min_nbr(head_a);
	if (min_pos == 1 || min_pos == 2)
		ra(&head_a);
	if (min_pos == 2)
		ra(&head_a);
	if (min_pos == 3)
		rra(&head_a);
	if (min_pos == 3 || min_pos == 4)
		rra(&head_a);
	pb(&head_a, &head_b);
	min_pos = position_min_nbr(head_a);
	if (min_pos == 1 || min_pos == 2)
		ra(&head_a);
	if (min_pos == 2)
		ra(&head_a);
	if (min_pos == 3)
		rra(&head_a);
	pb(&head_a, &head_b);
	head_a = sort_3(head_a);
	pa(&head_b, &head_a);
	pa(&head_b, &head_a);
	return (head_a);
}
