/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:21:45 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/12 15:22:50 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. Take *av[] as arguments.
2. Create linked list stack_a as t_node (structure in the push_swap.h file).
3. Handle single argument with ft_split.
4. Handle multiple arguments by converting string argument to int with.
	custom_atoi and adding the ints to the linked list 'stack_a' with add_node.
5. Perform data integrity checks (duplicates, valid integers) w/perform_checks.
6. Select and apply sorting algorithms based on the size of the stack.
7. Release all allocated memory before program termination with free_all. */
int	main(int ac, char **av)
{
	int		i;
	t_node	*stack_a;

	i = 1;
	stack_a = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == 0)
		{
			free_all(stack_a, ac, av);
			write(2, "Error\n", 6);
			exit(1);
		}
		i = 0;
	}
	if (ac > 1)
		while (av[i])
			stack_a = add_node(stack_a, custom_atoi(av[i++], stack_a, ac, av));
	perform_checks(stack_a, ac, av);
	stack_a = pick_sort(stack_a);
	return (free_all(stack_a, ac, av));
}
