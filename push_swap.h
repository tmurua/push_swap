/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:22:59 by tmurua            #+#    #+#             */
/*   Updated: 2024/06/20 19:26:15 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

/* Doubly linked list:
nbr: Number (integer) stored in the node
index: Integer to store index associated with node, used for sorting algorithms
prev: Pointer to previous node in the list
next: Pointer to next node in the list */
typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

/*	utils_free.c	*/
void				free_lst(t_node *head);
int					free_all(t_node *stack_a, int ac, char **av);

/*	util_atoi.c	*/
int					custom_atoi(const char *s, t_node *stack_a, int ac,
						char **av);

/*	utils_stack.c	*/
t_node				*add_node(t_node *head, int nbr);
t_node				*last_node(t_node *stack);
int					stack_size(t_node *head);
int					position_min_nbr(t_node *head);
int					position_max_index(t_node *head);

/*	utils_check.c	*/
void				perform_checks(t_node *stack_a, int ac, char **av);
int					has_duplicates(t_node *head);
int					is_too_big(t_node *head);
int					is_sorted(t_node *head);

/*	pick_sort.c	*/
t_node				*pick_sort(t_node *stack_a);

/*	sort_small.c	*/
t_node				*sort_2(t_node *head_a);
t_node				*sort_3(t_node *head_a);
t_node				*sort_4(t_node *head_a, t_node *head_b);
t_node				*sort_5(t_node *head_a, t_node *head_b);

/*	sort_big.c	*/
t_node				*sort_big(t_node *head_a, t_node *head_b);
void				assign_indexes(t_node *head_a);
void				atob_interval(t_node **head_a, t_node **head_b);
void				btoa_max(t_node **head_a, t_node **head_b);

/*	ops_push.c	*/
void				pa(t_node **head_b, t_node **head_a);
void				pb(t_node **head_a, t_node **head_b);

/*	ops_reverse_rotate.c	*/
void				rra(t_node **head);
void				rrb(t_node **head);

/*	ops_rotate.c	*/
void				ra(t_node **head);
void				rb(t_node **head);

/*	ops_swap.c	*/
void				sa(t_node **head);
void				sb(t_node **head);

#endif
