/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/14 18:43:49 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_non_integer_input(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[i])
	{
		y = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			y++;
		if (argv[i][y] >= '0' && argv[i][y] <= '9')
			while (argv[i][y] >= '0' && argv[i][y] <= '9')
				y++;
		else
			return (1);
		if (argv[i][y] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(char **argv)
{
	int	current_arg;
	int	next_arg;
	int	current_value;
	int	next_value;

	current_arg = 0;
	while (argv[current_arg])
	{
		next_arg = current_arg + 1;
		current_value = ft_atoi(argv[current_arg]);
		while (argv[next_arg])
		{
			next_value = ft_atoi(argv[next_arg]);
			if (current_value == next_value)
				return (1);
			next_arg++;
		}
		current_arg++;
	}
	return (0);
}

int	check_underflow_overflow(char **argv)
{
	int		i;
	long	current_argv;

	i = 0;
	while (argv[i])
	{
		current_argv = ft_atol(argv[i]);
		if (current_argv < INT_MIN || current_argv > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	check_if_stack_a_is_sorted(t_stack *stack_a)
{
	t_node	*current_node;

	current_node = stack_a->first;
	while (current_node && current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

void	check_which_algorithm_to_use(t_stack *stack_a, t_stack *stack_b)
{
	if (check_if_stack_a_is_sorted(stack_a) == 0)
		return ;
	else if (stack_a->size == 2)
		swap_a_sa(stack_a);
	else if (stack_a->size == 3)
		sort_stack_with_3_nodes(stack_a);
	else if (stack_a->size == 4)
		sort_stack_with_4_nodes(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_stack_with_5_nodes(stack_a, stack_b);
	else
		turk_sort(stack_a, stack_b);
}
