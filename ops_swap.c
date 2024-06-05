/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:44 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:24:31 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	if (stack_size(*head) == 2)
	{
		*head = (*head)->next;
		(*head)->next = (*head)->prev;
		(*head)->prev = NULL;
		(*head)->next->prev = *head;
		(*head)->next->next = NULL;
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev->next = (*head)->next;
		(*head)->prev->prev = *head;
		(*head)->next->prev = (*head)->prev;
		(*head)->next = (*head)->prev;
		(*head)->prev = NULL;
	}
}

void	sa(t_node **head)
{
	swap(head);
	ft_printf("sa\n");
}

void	sb(t_node **head)
{
	swap(head);
	ft_printf("sb\n");
}
