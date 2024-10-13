/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:41:08 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/13 23:10:53 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	check if there are at least 2 nodes to rotate, then call helper ft */
void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	rotate_first_to_last(stack, stack->first, stack->last);
}

/* remove og_first node from top, append it to bottom and update last node */
void	rotate_first_to_last(t_stack *stack, t_node *og_first, t_node *og_last)
{
	stack->first = og_first->next;
	stack->first->previous = NULL;
	og_last->next = og_first;
	og_first->previous = og_last;
	og_first->next = NULL;
	stack->last = og_first;
}

void	rotate_a_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
