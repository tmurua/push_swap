/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:21:54 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/03 17:22:21 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	if (*dst == NULL)
	{
		*src = (*src)->next;
		*dst = (*src)->prev;
		(*dst)->next = NULL;
		(*dst)->prev = NULL;
		(*src)->prev = NULL;
	}
	else if ((*src)->next == NULL)
	{
		(*src)->next = *dst;
		(*dst)->prev = *src;
		*dst = *src;
		*src = NULL;
	}
	else
	{
		*src = (*src)->next;
		(*src)->prev->next = *dst;
		*dst = (*src)->prev;
		(*dst)->next->prev = *dst;
		(*src)->prev = NULL;
	}
}

void	pb(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
	ft_printf("pb\n");
}

void	pa(t_node **head_b, t_node **head_a)
{
	push(head_b, head_a);
	ft_printf("pa\n");
}
