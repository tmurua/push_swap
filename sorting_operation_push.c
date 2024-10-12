/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:57:47 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/12 23:09:16 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	check if source stack is empty, if not, remove first node from it
	then insert it at the top of the destination stack */
void	push(t_stack *stack_src, t_stack *stack_dst)
{
	t_node	*node_to_move;

	if (stack_src->size == 0)
		return ;
	node_to_move = remove_node_src(stack_src, stack_src->first);
	insert_node_dst(stack_dst, node_to_move);
}

/*	if stack's empty after removing node, set last( only) node to NULL
	otherwise, set previous to new first node to NULL */
t_node	*remove_node_src(t_stack *src, t_node *node_to_move)
{
	src->first = node_to_move->next;
	if (src->first == NULL)
		src->last = NULL;
	else
		src->first->previous = NULL;
	src->size--;
	node_to_move->next = NULL;
	node_to_move->previous = NULL;
	return (node_to_move);
}

/*	if stack was empty, node_tomove becomes last node
	otherwise it becomes previous node to og first, i.e. the new first node */
void	insert_node_dst(t_stack *dst, t_node *node_to_move)
{
	node_to_move->next = dst->first;
	if (dst->first == NULL)
		dst->last = node_to_move;
	else
		dst->first->previous = node_to_move;
	dst->first = node_to_move;
	dst->size++;
}

void	push_to_a_pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_to_b_pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
