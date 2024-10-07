# push_swap

## push_swap.h
#ifndef PUSH_SWAP_H
'# define PUSH_SWAP_H

'# include <unistd.h>
'# include <stdlib.h>
'# include "/libft/libft.h"

/* macros*/


/* structures */
typedef	struct s_stack_a
{
	int		element_value_a;
	int		element_index_a;
	struct	*next_a;
	struct	*previous_a;
}	t_stack_a

typedef	struct s_stack_b
{
	int		element_value_b;
	int		element_index_b;
	struct	*next_b;
	struct	*previous_b;
}	t_stack_b


/* function prototypes */
/* main.c */
int		handle_input(int argc, char **argv, t_stack_a stack_a);
void	try_input_again();
void	wrong_input(void);

/* sorting_operations.c */


#endif

---

## main.c
### handle_input()
int	handle_input(int argc, char **argv, t_stack_a stack_a) //maybe separate in more functions to keep SPP and modularity

if (argc ==2 ) // i.e. stack_a = argv[1]
	// (ft_split, then ft_atoi)

if (argc > 1)
	// argv[n] (ft_atoi)

stack_b = starts empty

if (argc == 1) // i.e. stack_a == NULL
	return (1)

if stack_a has 2 duplicate numbers
{
	wrong_input()
	return (0)
}
if stack_a has non integer elements
{
	wrong_input()
	return (0)
}

if stack_a has elements > integer
{
	wrong_input()
	return (0)
}

### wrong_input()
void	wrong_input(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
---
## sorting_algorithm.c
1. Research which algorithm or algorithms would be best (easy to read, easy to write, sorts number within limits, i.e. sort 100 random numbers in fewer than 700 operations)
	- turk algorithm seems a good option
	- using different algorithms for stack with less than 5 numbers and more than 5 numbers also seems a good idea
2. implementation must input the structs t_stack_a and t_stack_b and output the sorting_operations

---

## sorting_operations_a.c
### swap_a_sa()
// swap 2 top elements of stack_a
ft_printf("sa\n");

### push_to_a_pa()
//Take top element of stack_b and put it at top of stack_a
//if stack_b is empty, do nothing
ft_printf("pa\n");

### rotate_a_ra()
// top element of stack_a becomes bottom element of stack_a
ft_printf("ra\n");

### reverse_rotate_a_rra()
// bottom element of stack_a becomes top element of stack_a
ft_printf("rra\n");

---

## sorting_operations_b.c
### swap_b_sb()
// swap 2 top elements of stack_b
ft_printf("sb\n");

### push_to_b_pb()
//Take top element of stack_a and put it at top of stack_b
//if stack_a is empty, do nothing
ft_printf("pb\n");

### rotate_b_rb()
// top element of stack_b becomes bottom element of stack_b
ft_printf("rb\n");

### reverse_rotate_b_rrb()
// bottom element of stack_b becomes top element of stack_b
ft_printf("rrb\n");

---

## sorting_operations_both.c
### swap_swap_ss()
swap_a_sa();
swap_b_sb();

### rotate_rotate_rr()
rotate_a_ra();
rotate_b_rb();

### reverse_rotate_rotate_rrr()
reverse_rotate_a_rra();
reverse_rotate_b_rrb();
