/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation_reverse_rotate.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:39:13 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/12 12:35:59 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	check if there are at least 2 nodes to rotate, then call helper ft */
void	reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	revers_last_to_first(stack, stack->last, stack->first);
}

/* remove og_last node from bottom, append it to top and update first node */
void	revers_last_to_first(t_stack *stack, t_node *og_last, t_node *og_first)
{
	stack->last = og_last->previous;
	og_first->previous = og_last;
	og_last->next = og_first;
	og_last->previous = NULL;
	stack->first = og_last;
}

void	reverse_rotate_a_rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b_rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
