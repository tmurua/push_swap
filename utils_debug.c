/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:23:50 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:24:18 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Prints the nbr of each node in the linked list. */
void	print_stack_nbr(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		ft_printf("nbr node[%d]: %d\n", i, head->nbr);
		head = head->next;
		i++;
	}
}

/* Prints the index and nbr of each node in the linked list. */
void	print_stack_index_nbr(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		ft_printf("index | nbr node[%d]: %d | %d\n", i, head->index,
			head->nbr);
		head = head->next;
		i++;
	}
}
