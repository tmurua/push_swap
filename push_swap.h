/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:06:02 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/07 11:23:39 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* macros*/


/* structures */
typedef struct s_element
{
	int			value;
	int			index;
	t_element	*next;
	t_element	*previous;
}	t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*bottom;
	int			size;
}	t_stack;


/* function prototypes */
/* main.c */
int		handle_input(int argc, char **argv, t_stack *stack);
void	wrong_input(void);

/* sorting_operations.c */


#endif
