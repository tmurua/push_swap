/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:43 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/20 19:43:49 by tmurua           ###   ########.fr       */
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

/* Checks for duplicate numbers in the linked list. */
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
This is necessary to assign correct indexes with the assign_index function. */
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

/* Checks if the numbers in the linked list are in sorted order. */
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
