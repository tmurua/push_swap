/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:52 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/23 23:44:36 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Chooses the appropriate sorting algorithm based on the size of the stack.
1. Initialize stack_b to NULL and get the size of stack_a
2. If the size of stack_a is less than 2, return stack_a as it's already sorted
3. Use the appropriate sorting function based on the size of stack_a:
	- For sizes 2 to 5, call the corresponding sort function from sort_small.c
	- For sizes greater than 5, call sort_big */
t_node	*pick_sort(t_node *stack_a)
{
	t_node	*stack_b;
	int		size_a;

	stack_b = NULL;
	size_a = stack_size(stack_a);
	if (size_a < 2)
		return (stack_a);
	else if (size_a == 2)
		return (sort_2(stack_a));
	else if (size_a == 3)
		return (sort_3(stack_a));
	else if (size_a == 4)
		return (sort_4(stack_a, stack_b));
	else if (size_a == 5)
		return (sort_5(stack_a, stack_b));
	else
		return (sort_big(stack_a, stack_b));
	return (0);
}
