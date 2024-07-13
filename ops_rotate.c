/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:13 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/12 19:26:41 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotate the stack upwards (move the first element to the last position).
1. OG 2nd node becomes the current head: *head = (*head)->next;
2. OG 1st node's prev is assigned to the last node.
3. OG 1st node's next is assigned to NULL.
4. The last node's next is assigned to OG 1st node.
5. OG 2nd node's prev is assigned to NULL.
NULL<- OG 2nd node<->OG 3rd node<-> ... <->OG last node<->OG 1st node ->NULL*/
static void	rotate(t_node **head)
{
	*head = (*head)->next;
	(*head)->prev->prev = last_node(*head);
	(*head)->prev->next = NULL;
	(*head)->prev->prev->next = (*head)->prev;
	(*head)->prev = NULL;
}

/* Rotate stack A upwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the rotate operation.
3. Print the operation "ra". */
void	ra(t_node **head)
{
	if (!(*head))
		return ;
	if (!((*head)->next))
		return ;
	rotate(head);
	ft_printf("ra\n");
}

/* Rotate stack B upwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the rotate operation.
3. Print the operation "rb". */
void	rb(t_node **head)
{
	if (!(*head))
		return ;
	if (!((*head)->next))
		return ;
	rotate(head);
	ft_printf("rb\n");
}
