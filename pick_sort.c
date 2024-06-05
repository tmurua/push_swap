/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:52 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:24:27 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Selects the sorting algorithm based on the size of the linked list. */
t_node	*pick_sort(t_node *stack_a)
{
	t_node	*stack_b;
	int		size_a;

	stack_b = NULL;
	size_a = stack_size(stack_a);
	if (size_a < 2)
		return (stack_a);
	if (size_a == 2)
		return (sort_2(stack_a));
	if (size_a == 3)
		return (sort_3(stack_a));
	if (size_a == 4)
		return (sort_4(stack_a, stack_b));
	if (size_a == 5)
		return (sort_5(stack_a, stack_b));
	if (size_a > 5)
		return (sort_big(stack_a, stack_b));
	return (0);
}
