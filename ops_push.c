/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:21:54 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/12 19:57:27 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Push the top element from the source stack to the destination stack.
1. If destination stack is empty, perform initial push:
1.1 Move head of src to the next node: *src = (*src)->next;
1.2 OG 1st node of src becomes the head of dst: *dst = (*src)->prev;
1.3 NULL is assigned to OG 1st node of dst's next: (*dst)->next = NULL;
1.4 NULL is assigned to OG 1st node of dst's prev: (*dst)->prev = NULL;
1.5 NULL is assigned to the new head of src's prev: (*src)->prev = NULL;
	NULL <- OG 1st node of dst (new head) -> NULL
2. If src stack has only one element, push it to dst:
2.1 OG 1st node's next assigned to dst: (*src)->next = *dst;
2.2 OG 1st node becomes dst's prev: (*dst)->prev = *src;
2.3 OG 1st node becomes the new head of dst: *dst = *src;
2.4 NULL is assigned to src: *src = NULL;
	OG 1st node of dst (new head) <-> OG 1st node of dst's next -> NULL
3. If src stack has more than one element, perform general push:
3.1 Move head of src to the next node: *src = (*src)->next;
3.2 OG 2nd node's next assigned to dst: (*src)->prev->next = *dst;
3.3 OG 1st node of src becomes the new head of dst: *dst = (*src)->prev;
3.4 dst's prev assigned to dst: (*dst)->next->prev = *dst;
3.5 NULL is assigned to the new head of src's prev: (*src)->prev = NULL;
NULL<-OG 1st node (new head)<->OG 2nd node<->...<->OG last node ->NULL */
#include "push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	if (*dst == NULL)
	{
		*src = (*src)->next;
		*dst = (*src)->prev;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
		(*src)->prev = NULL;
	}
	else if ((*src)->next == NULL)
	{
		(*src)->next = *dst;
		(*dst)->prev = *src;
		*dst = *src;
		*src = NULL;
	}
	else
	{
		*src = (*src)->next;
		(*src)->prev->next = *dst;
		*dst = (*src)->prev;
		(*dst)->next->prev = *dst;
		(*src)->prev = NULL;
	}
}

/* Push the top element from stack_a to stack_b and print "pb".
1. Perform the push operation.
2. Print the operation "pb". */
void	pb(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
	ft_printf("pb\n");
}

/* Push the top element from stack_b to stack_a and print "pa".
1. Perform the push operation.
2. Print the operation "pa". */
void	pa(t_node **head_b, t_node **head_a)
{
	push(head_b, head_a);
	ft_printf("pa\n");
}
