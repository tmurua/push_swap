/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:24:07 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:24:14 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Adds a new node with the specified number to the end of the linked list. */
t_node	*add_node(t_node *head, int nbr)
{
	t_node	*last;
	t_node	*new;

	last = last_node(head);
	new = NULL;
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;
	new->next = NULL;
	if (last == NULL)
	{
		new->prev = NULL;
		return (new);
	}
	else
	{
		last->next = new;
		new->prev = last;
		return (head);
	}
}

/* Returns the size of the linked list.
Raises an error if the size equals or exceeds INT_MAX. */
int	stack_size(t_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size++;
	}
	return (size);
}

/* Returns a pointer to the last node in the linked list.
If the list is empty, returns NULL. */
t_node	*last_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* Returns the position of the minimum element in the linked list. */
int	position_min_nbr(t_node *head)
{
	int		min;
	int		i;
	t_node	*tmp;

	min = head->nbr;
	tmp = head;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	i = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->nbr == min)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

/* Returns the position of the maximum index in the linked list. */
int	position_max_index(t_node *head)
{
	int		max;
	int		i;
	t_node	*tmp;

	max = head->index;
	tmp = head;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	i = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->index == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
