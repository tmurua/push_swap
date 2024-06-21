/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:24:07 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/21 02:48:37 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Adds a new node with the specified number to the end of the linked list.
1. Find last node in the linked list using last_node: last = last_node(head);
2. Allocate memory for a new node
3. Initialize the new node with the given number
4. Set index to -1 to indicate it hasn't been assigned yet
5. Initialize next pointer to NULL, since new node wil be the last in the list
6. If the list is empty, set the new node as the head: new->prev = NULL;
7. If it isn't, add new node to the end: last->next = new; new->prev = last; */
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

/*	1. Check if the list is empty, if so returns NULL
	2. Traverse the list until stack->next is NULL, i.e. last node was found
	3. Return a pointer to the last node found in the linked list */
t_node	*last_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*	1. Initialize size to 0.
	2. Traverse the linked list from head to end.
	3. Increment size for each node encountered.
	4. Return the size of the linked list. */
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
