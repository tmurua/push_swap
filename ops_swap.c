/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:44 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/12 18:56:58 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements at the top of the stack.
1. If stack contains exactly 2 elements, perform a simple swap for 2 elements.
	if (stack_size(*head) == 2)
1.1 OG 2nd node becomes the current head: *head = (*head)->next;
1.2 OG 2nd node's prev assigned to OG 2nd node's next, i.e. to OG 1st node:
	(*head)->next = (*head)->prev;
1.3 NULL is assigned to OG 2nd node's prev: (*head)->prev = NULL;
1.4 The current head (OG 2nd node) is assigned to OG 1st node's prev:
	(*head)->next->prev = *head;
1.5 NULL is assigned to OG 1st node's next: (*head)->next->next = NULL;
	NULL <- OG 2nd node <-> OG 1st node -> NULL
2. If stack has more than 2 elements, perform swap for more than 2 elements: else
2.1 OG 2nd node becomes the current head: *head = (*head)->next;
2.2 OG 2nd node's next assigned to OG 1st node's next, i.e. to OG 3rd node:
	(*head)->prev->next = (*head)->next;
2.3 OG 2nd node assigned to OG 1st node's prev: (*head)->prev->prev = *head;
2.4 OG 2nd node's prev, i.e. 1st node, is assigned to OG 3rd node prev:
	(*head)->next->prev = (*head)->prev;
2.5 OG 2nd node's prev, i.e. OG 1st node, is assigned to OG 2nd node's next:
	(*head)->next = (*head)->prev;
2.6 NULL is assigned to OG 2nd node's prev: (*head)->prev = NULL;
	NULL <- OG 2nd node <-> OG 1st node <-> OG 3rd node -> NULL */
static void	swap(t_node **head)
{
	if (stack_size(*head) == 2)
	{
		*head = (*head)->next;
		(*head)->next = (*head)->prev;
		(*head)->prev = NULL;
		(*head)->next->prev = *head;
		(*head)->next->next = NULL;
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev->next = (*head)->next;
		(*head)->prev->prev = *head;
		(*head)->next->prev = (*head)->prev;
		(*head)->next = (*head)->prev;
		(*head)->prev = NULL;
	}
}

/* Swaps the first two elements at the top of stack_a and prints "sa". */
void	sa(t_node **head)
{
	swap(head);
	ft_printf("sa\n");
}

/* Swaps the first two elements at the top of stack_b and prints "sb". */
void	sb(t_node **head)
{
	swap(head);
	ft_printf("sb\n");
}
