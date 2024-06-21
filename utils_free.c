/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:58 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/21 01:55:26 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. Traverse the linked list.
2. Save the next node to a temporary node tmp.
3. Free the memory allocated for the current node.
4. Move to the next node by setting head to tmp, saved as the next node. */
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

/*
1. Free the memory allocated for the linked list using free_lst.
2. If av is NULL, return.
3. If ac is 2, free each element in av and then free av itself.
	- Iterate through the av array: while (av[i])
	- Free each string in av: free (av[i]); i++;
	- Free the array of strings av: free (av);
4. Return 0 to indicate successful memory cleanup */
int	free_all(t_node *stack_a, int ac, char **av)
{
	int	i;

	free_lst(stack_a);
	if (av == 0)
		return (0);
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
