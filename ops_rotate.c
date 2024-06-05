/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:13 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:22:22 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	*head = (*head)->next;
	(*head)->prev->prev = last_node(*head);
	(*head)->prev->next = NULL;
	(*head)->prev->prev->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ra(t_node **head)
{
	if (!(*head))
		return ;
	if (!((*head)->next))
		return ;
	rotate(head);
	ft_printf("ra\n");
}

void	rb(t_node **head)
{
	if (!(*head))
		return ;
	if (!((*head)->next))
		return ;
	rotate(head);
	ft_printf("rb\n");
}
