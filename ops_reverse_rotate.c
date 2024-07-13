/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:04 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/12 19:28:43 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reverse rotate the stack (move the last element to the first position).
1. OG last node assigned to head's prev (1st): (*head)->prev = last_node(*head);
2. Current head assigned to OG last node's next: (*head)->prev->next = *head;
3. NULL assigned to OG 2nd to last node's next:(*head)->prev->prev->next = NULL;
4. NULL assigned to OG last node's prev: (*head)->prev->prev = NULL;
5. The head is updated to point to the last node: *head = (*head)->prev
	NULL <- OG last node <-> OG 1st node <-> OG 2nd node -> NULL */
static void	reverse_rotate(t_node **head)
{
	(*head)->prev = last_node(*head);
	(*head)->prev->next = *head;
	(*head)->prev->prev->next = NULL;
	(*head)->prev->prev = NULL;
	*head = (*head)->prev;
}

/* Reverse rotate stack A downwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the reverse rotate operation.
3. Print the operation "rra". */
void	rra(t_node **head)
{
	reverse_rotate(head);
	ft_printf("rra\n");
}

/* Reverse rotate stack B downwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the reverse rotate operation.
3. Print the operation "rrb". */
void	rrb(t_node **head)
{
	reverse_rotate(head);
	ft_printf("rrb\n");
}
