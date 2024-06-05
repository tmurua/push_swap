/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:58 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:24:17 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees the memory allocated for the linked list. */
void	free_lst(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/* Frees all memory allocated in the main function,
including linked list and command line arguments. */
int	free_all(t_node *stack_a, int ac, char **av)
{
	int	i;

	free_lst(stack_a);
	if (av == 0)
	{
		free(av);
		return (0);
	}
	i = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	return (0);
}
