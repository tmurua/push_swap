/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/11 15:47:04 by tmurua           ###   ########.fr       */
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
		i++;
	}
	return (0);
}

int	check_duplicates(char **argv)
{
	int	i;
	int	y;

	i = 0;
	while (argv[i])
	{
		y = i + 1;
		while (argv[y])
		{
			if (!ft_strncmp(argv[i], argv[y], ft_strlen(argv[i])))
				return (1);
			y++;
		}
		i++;
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
		current_argv = ft_atoi(argv[i]);
		if (current_argv < INT_MIN || current_argv > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

void	populate_stack_a(int argc, char **argv, t_stack *stack_a)
{
	t_node	*next_node;
	t_node	*previous_node;
	int		i;

	i = 0;
	previous_node = NULL;
	while (argv[i])
	{
		next_node = create_node(ft_atoi(argv[i]), i, stack_a);
		next_node->previous = previous_node;
		if (previous_node)
			previous_node->next = next_node;
		else
			stack_a->first = next_node;
		previous_node = next_node;
		i++;
	}
	stack_a->last = previous_node;
	stack_a->size = argc;
}

t_node	*create_node(int value, int index, t_stack *stack_a)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		wrong_input(stack_a);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
