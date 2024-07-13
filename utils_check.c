/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:43 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/12 18:51:57 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Perform data integrity checks (duplicates, valid integers).
1. Check if the stack contains any integers that are too large.
2. Check for duplicate values in the stack.
3. If any of the above checks fail, free all allocated memory,
	print an error message, and exit with an error status.
4. Check if the stack is already sorted.
5. If the stack is sorted, free all allocated memory and exit successfully. */
void	perform_checks(t_node *stack_a, int ac, char **av)
{
	if (is_too_big(stack_a) || has_duplicates(stack_a))
	{
		free_all(stack_a, ac, av);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(stack_a))
	{
		free_all(stack_a, ac, av);
		exit(0);
	}
}

/* Checks for duplicate numbers in the linked list.
1. Traverse the linked list using the head node: while (head->next)
2. For each node, clone the current node using tmp: tmp = head;
3. Move tmp to the next node: tmp = tmp->next;
4. Compare the nbr value of tmp with the nbr value of head (next with current).
5. If a duplicate is found, return 1 (true).
6. If no duplicates are found after traversing the list, return 0 (false). */
int	has_duplicates(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return (0);
	while (head->next)
	{
		tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->nbr == head->nbr)
				return (1);
		}
		head = head->next;
	}
	return (0);
}

/* Checks if the size of the linked list is within limits.
This is necessary to assign correct indexes with the assign_index function.
1. Initialize size to 0.
2. Traverse the linked list, incrementing size.
3. If size equals INT_MAX, return 1 (true).
4. If the list is traversed without reaching INT_MAX, return 0 (false). */
int	is_too_big(t_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size++;
		if (size == INT_MAX)
			return (1);
	}
	return (0);
}

/* Checks if the numbers in the linked list are in sorted order.
1. Traverse the linked list using the head node: while (head->next)
2. For each node, clone the current node using tmp: tmp = head;
3. Move tmp to the next node: tmp = tmp->next;
4. Compare the nbr value of tmp with the nbr value of head.
5. If tmp (next nbr) is smaller then head (current nbr), return 0 (false).
6. If the list is traversed without finding smaller values, return 1 (true). */
int	is_sorted(t_node *head)
{
	t_node	*tmp;

	while (head->next)
	{
		tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (head->nbr > tmp->nbr)
				return (0);
		}
		head = head->next;
	}
	return (1);
}
