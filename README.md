# push_swap (next modules)
## sorting_operation_rotate.c
### rotate_a_ra()
// top element of stack_a becomes bottom element of stack_a
ft_printf("ra\n");

### rotate_b_rb()
// top element of stack_b becomes bottom element of stack_b
ft_printf("rb\n");

### rotate_rotate_rr()
rotate_a_ra();
rotate_b_rb();

---
## sorting_operation_reverse_rotate.c
### reverse_rotate_a_rra()
// bottom element of stack_a becomes top element of stack_a
ft_printf("rra\n");

### reverse_rotate_b_rrb()
// bottom element of stack_b becomes top element of stack_b
ft_printf("rrb\n");

### reverse_rotate_rotate_rrr()
reverse_rotate_a_rra();
reverse_rotate_b_rrb();

---
## sorting_operation_push.c
### push_to_a_pa()
//Take top element of stack_b and put it at top of stack_a
//if stack_b is empty, do nothing
ft_printf("pa\n");

### push_to_b_pb()
//Take top element of stack_a and put it at top of stack_b
//if stack_a is empty, do nothing
ft_printf("pb\n");

---
## sorting_algorithm.c
1. Research which algorithm or algorithms would be best (easy to read, easy to write, sorts number within limits, i.e. sort 100 random numbers in fewer than 700 operations)
	- turk algorithm seems a good option
	- using different algorithms for stack with less than 5 numbers and more than 5 numbers also seems a good idea
2. implementation must input the structs t_stack_a and t_stack_b and output the sorting_operations
