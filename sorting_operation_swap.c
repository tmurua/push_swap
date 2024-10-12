/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:48:05 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/12 11:23:07 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	check if there are at least 2 nodes to swap, then call helper ft
	updates the stack's last pointer if necessary */
void	swap(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	swap_first_two_nodes(stack, stack->first, stack->first->next);
	if (stack->size == 2)
		stack->last = stack->first->next;
}

/*	updates the stack->first pointer and adjusts links between the nodes
	if there's a third node, it also adjusts it's node->previous pointer */
void	swap_first_two_nodes(t_stack *stack, t_node *og_first, t_node *second)
{
	og_first->next = second->next;
	if (second->next)
		second->next->previous = og_first;
	second->previous = og_first->previous;
	second->next = og_first;
	og_first->previous = second;
	stack->first = second;
}

void	swap_a_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
