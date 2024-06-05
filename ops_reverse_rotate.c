/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:04 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:22:25 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	(*head)->prev = last_node(*head);
	(*head)->prev->next = *head;
	(*head)->prev->prev->next = NULL;
	(*head)->prev->prev = NULL;
	*head = (*head)->prev;
}

void	rra(t_node **head)
{
	reverse_rotate(head);
	ft_printf("rra\n");
}

void	rrb(t_node **head)
{
	reverse_rotate(head);
	ft_printf("rrb\n");
}
