/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:21:45 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/16 18:59:49 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. Take *av[] as arguments. i used as the index for each av[]
2. Create linked list stack_a as t_node (structure in push_swap.h file)
3. Handle case with no arguments: if (ac == 1) and edge cases
4. Handle single argument with ft_split: if (ac == 2)
	- Split the single argument into an array of arguments
	- Handle the case where splitting fails
	- Process split arguments from start, without program name: i = 0
5. Handle multiple arguments: if (ac > 1)
	- Convert current string argument (av[i]) to int with custom_atoi, then i++
	- Add current int as node to the linked list 'stack_a' with add_node
6. Perform data integrity checks (duplicates, valid integers) w/perform_checks.
7. Select and apply sorting algorithms based on the size of the stack.
8. Release all allocated memory before program termination with free_all. */
int	main(int ac, char **av)
{
	int		i;
	t_node	*stack_a;

	i = 1;
	stack_a = NULL;
	if (ac == 1 || (ac == 2 && handle_edge_cases(av[1])))
		return (1);
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
