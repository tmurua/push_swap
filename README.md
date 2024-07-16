# push_swap

## Overview

The **`push_swap`** project is a programming exercise aimed at sorting a stack of integers using a specified set of operations in the fewest steps possible. Instead of directly sorting the numbers, the program outputs a sequence of operations that, when applied, will sort the stack.

These operations are:

- **Swapping**: `sa`, `sb`, `ss`
- **Pushing**: `pa`, `pb`
- **Rotating**: `ra`, `rb`, `rr`
- **Reverse Rotating**: `rra`, `rrb`, `rrr`
    
    ### Primary Goal
    
    The primary goal of the project is to practice algorithm optimization and stack manipulation. It is valuable for:
    
    - Understanding efficient sorting algorithms
    - Mastering stack operations
    - Preparing for algorithm-related technical interviews
    
    ### Usage
    
    1. **Compilation:**
    Use the provided Makefile to compile the program.
        
        ```
        make
        ```
        
    2. **Running the Program:**
    Execute the program with a list of integers as arguments.
        
        ```
        ./push_swap 3 2 1
        ```
        
        output:
        
        ```
        ./push_swap 3 2 1
        sa
        rra
        ```
        
    3. **Error Handling:**
    The program will output "Error" if invalid inputs are provided (e.g., non-integer values, duplicates).
    
    ### Operations
    
    The program utilizes the following operations to manipulate the stacks:
    
    - **Swap:**
        - `sa`: Swap the top two elements of stack A
        - `sb`: Swap the top two elements of stack B
        - `ss`: Swap the top two elements of both stacks
    - **Push:**
        - `pa`: Move the top element of stack B to stack A
        - `pb`: Move the top element of stack A to stack B
    - **Rotate:**
        - `ra`: Shift all elements of stack A up by one
        - `rb`: Shift all elements of stack B up by one
        - `rr`: Shift all elements of both stacks up by one
    - **Reverse Rotate:**
        - `rra`: Shift all elements of stack A down by one
        - `rrb`: Shift all elements of stack B down by one
        - `rrr`: Shift all elements of both stacks down by one
    
    ### Algorithm
    
    1. **Small Stack Sorting (5 elements or fewer):**
        - Implement a simple sorting algorithm tailored for small stacks.
    2. **Large Stack Sorting (6 elements or more):**
        - Use a distribution sort algorithm:
            - **Assign Indexes:** Assign indexes to elements for easier interval management.
            - **atob_interval:** Move elements from stack A to stack B based on indexed intervals.
            - **btoa_max:** Move elements back to stack A from stack B by finding the largest indexed element and pushing it back to stack A.
    
    ### Example
    
    Let's consider sorting the list `2 1 3 6 5 8`:
    
    1. **Initial State:**
        
        ```less
        Stack A: 2 1 3 6 5 8
        Stack B: (empty)
        ```
        
    2. **Operation Sequence:**
        
        ```
        sa       => Swap top two of A: 1 2 3 6 5 8
        pb pb pb => Push three elements from A to B: 6 5 8 | 3 2 1
        rr       => Rotate both A and B: 5 8 6 | 2 1 3
        rrr      => Reverse rotate both A and B: 6 5 8 | 3 2 1
        sa       => Swap top two of A: 5 6 8 | 3 2 1
        pa pa pa => Push three elements from B to A: 1 2 3 5 6 8
        ```
        
    3. **Final State:**
        
        ```less
        Stack A: 1 2 3 5 6 8
        Stack B: (empty)
        ```
        
    
    The sequence above sorts the stack with 10 operations.
    

## Implementation

### push_swap.h

```c
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
    int             nbr;    // The value stored in the node
    int             index;  // An additional index field, can be used for sorting or tracking
    struct s_node   *prev;  // Pointer to the previous node in the list
    struct s_node   *next;  // Pointer to the next node in the list
}                   t_node;

/*	utils_free.c	*/
void				free_lst(t_node *head);
int					free_all(t_node *stack_a, int ac, char **av);

/*	utils_args.c	*/
int					custom_atoi(const char *s, t_node *stack_a, int ac,
						char **av);
int					handle_edge_cases(const char *str);

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
```

### Doubly Linked List

This structure is for a **doubly linked list** because each node contains pointers to both the previous and next nodes. This allows for easier traversal in both directions compared to a singly linked list, which only has a pointer to the next node.

### Visualization

Here's a simple visualization of how nodes in this doubly linked list would be linked together:

```
NULL <-> [prev | nbr | index | next] <-> [prev | nbr | index | next] <-> NULL
```

- Each node points to the previous node through `prev` and to the next node through `next`.
- The list can be traversed from any node to either the start or the end.

### Summary

- **`t_node`**: Defines a node in a doubly linked list.
- **Fields**:
    - `nbr`: Stores the node's value.
    - `index`: Stores an index value (useful for sorting or other algorithms).
    - `prev`: Pointer to the previous node.
    - `next`: Pointer to the next node.

### main.c

```c
#include "push_swap.h"

/*
1. Take *av[] as arguments. i used as the index for each av[]
2. Create linked list stack_a as t_node (structure in push_swap.h file)
3. Handle case with no arguments: if (ac == 1) and edge cases
4. Handle single argument with ft_split: if (ac == 2)
	- Split the single argument into an array of arguments
	- Handle the case where splitting fails
	- Process split arguments from start, without program name: i = 0
5. Handle multiple arguments: if (ac > 1)
	- Convert current string argument (av[i]) to int with custom_atoi, then i++
	- Add current int as node to the linked list 'stack_a' with add_node
6. Perform data integrity checks (duplicates, valid integers) w/perform_checks.
7. Select and apply sorting algorithms based on the size of the stack.
8. Release all allocated memory before program termination with free_all. */
int main(int ac, char **av)
{
    int     i;
    t_node  *stack_a;

    // Step 2: Create linked list stack_a
    i = 1;
    stack_a = NULL;
    
    // Step 3: Handle case with no arguments and edge cases
	 	if (ac == 1 || (ac == 2 && handle_edge_cases(av[1])))
        return (0);
    
    // Step 4: Handle single argument with ft_split
    if (ac == 2)
    {
        // Split the single argument into an array of arguments
        av = ft_split(av[1], ' ');
        // Handle the case where splitting fails
        if (av == 0)
        {
            free_all(stack_a, ac, av);
            write(2, "Error\n", 6);
            exit(1);
        }
        i = 0; // Process split arguments from the start (i = 0)
    }
    
    // Step 5: Handle multiple arguments
    if (ac > 1)
        while (av[i])
            stack_a = add_node(stack_a, custom_atoi(av[i++], stack_a, ac, av));
    
    // Step 6: Perform data integrity checks
    perform_checks(stack_a, ac, av);
    
    // Step 7: Select and apply sorting algorithms
    stack_a = pick_sort(stack_a);
    
    // Step 8: Release all allocated memory
    return (free_all(stack_a, ac, av));
}
```

### utils_free.c

```c
#include "push_swap.h"

/*
1. Traverse the linked list.
2. Save the next node to a temporary node tmp.
3. Free the memory allocated for the current node.
4. Move to next node by setting head to tmp, saved as next node. */
void free_lst(t_node *head)
{
    t_node *tmp;

    while (head) // Step 1: Traverse the linked list.
    {
        tmp = head->next; // Step 2: Save the next node.
        free(head);       // Step 3: Free the current node.
        head = tmp;       // Step 4: Move to the next node.
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
int free_all(t_node *stack_a, int ac, char **av)
{
    int i;

    // Step 1: Free the memory allocated for the linked list.
    free_lst(stack_a);

    // Step 2: If av is NULL, return.
    if (av == 0)
        return (0); // Return after freeing.

    i = 0;
    // Step 3: If ac is 2, free each element in av and then free av itself.
    if (ac == 2)
    {
        // Step 3.1: Iterate through the av array.
        while (av[i])
        {
            free(av[i]); // Step 3.2: Free each string in av.
            i++;
        }
        free(av); // Step 3.3: Free the array of strings.
    }

    // Step 4: Return 0 to indicate successful memory cleanup.
    return (0);
}
```

### `free_lst`

1. **Traverse the Linked List**: Iterates through each node in the linked list.
2. **Free Each Node**: For each node:
    - Save the pointer to the next node (`tmp = head->next`).
    - Free the current node (`free(head)`).
    - Move to the next node (`head = tmp`).

This process continues until all nodes in the linked list are freed.

### `free_all`

1. **Free the Linked List**: Calls `free_lst(stack_a)` to free all nodes in the linked list.
2. **Check if `av` is NULL**: If `av` is `NULL`, return `0`.
3. **Free Command Line Arguments**:
    - If `ac` is `2`, it indicates that the command-line arguments were passed as a single string and split into multiple arguments.
    - The function iterates through the `av` array, freeing each string (`free(av[i])`).
    - After freeing all individual strings, it frees the `av` array itself (`free(av)`).

### utils_args.c

```c
#include "push_swap.h"

/* Free allocated memory for stack_a, ac and av, and raise an error. */
static void free_error_exit(t_node *stack_a, int ac, char **av)
{
    free_all(stack_a, ac, av);
    write(2, "Error\n", 6);
    exit(1);
}

/* Convert a string to an integer with error handling.
1. Handle leading whitespace
2. Check for invalid input (empty string, invalid chars, or invalid sign)
3. Handle '+' or '-' sign
4. Convert numeric characters to an integer
5. Check for integer overflow or underflow */
int custom_atoi(const char *s, t_node *stack_a, int ac, char **av)
{
    int         i;
    int         sign;
    long long   number;

    i = 0;
    // 1. Handle leading whitespace
    while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
        i++;
    // 2. Check for invalid input (empty string or invalid sign)
    if (!s[i] || ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1])))
        free_error_exit(stack_a, ac, av);
    // 3. Handle '+' or '-' sign
    sign = 1;
    if (s[i] == '+' || s[i] == '-')
        if (s[i++] == '-')
            sign = -1;
    // 4. Convert numeric characters to an integer
    number = 0;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            free_error_exit(stack_a, ac, av);
        else
            number = number * 10 + (s[i] - '0');
        i++;
    }
    // 5. Check for integer overflow or underflow
    if ((sign * number < INT_MIN) || (sign * number > INT_MAX))
        free_error_exit(stack_a, ac, av);
    return (sign * number);
}

/* Handle edge cases for input validation
1. If the input string is empty, print "Error" and return 1.
2. Traverse the input string
	- For each character, check if it is not a whitespace character
	- If a non-whitespace character is found, return 0
3. If only whitespace chars were found, print "Error" and return 1 */
int	handle_edge_cases(const char *str)
{
	int	i;

	i = 0;
	// 1. If the input string is empty, print "Error" and return 1.
	if (ft_strlen(str) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	// 2. Traverse the input string
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			return (0);
		i++;
	}
	// 3. If only whitespace chars were found, print "Error" and return 1 */
	write(2, "Error\n", 6);
	return (1);
}
```

The parameters `stack_a`, `ac`, and `av` are passed to the `custom_atoi` function primarily for error handling. If an error occurs within `custom_atoi`, it can call `free_error_exit`, which uses these parameters to free all allocated memory, display an error message, and exit the program with a non-zero status.

### `custom_atoi`

The `custom_atoi` function converts a string `s` to an integer while handling potential errors. If an error occurs (e.g., invalid input, overflow, or underflow), it calls `free_error_exit` to clean up and terminate the program.

### `free_error_exit`

The `free_error_exit` function is responsible for:

1. Freeing all allocated memory using `free_all`.
2. Writing an error message to the standard error output.
3. Exiting the program with a non-zero status.

### Error Handling with `custom_atoi`

When `custom_atoi` detects an error:

1. It calls `free_error_exit` with the current `stack_a`, `ac`, and `av`.
2. `free_error_exit` then frees all dynamically allocated memory, prints "Error\n" to the standard error, and exits the program.

### utils_stack.c

```c
#include "push_swap.h"

/* Adds a new node with the specified number to the end of the linked list.
1. Find last node in the linked list using last_node: last = last_node(head);
2. Allocate memory for a new node
3. Initialize the new node with the given number
4. Set index to -1 to indicate it hasn't been assigned yet
5. Initialize next pointer to NULL, since new node wil be the last in the list
6. If the list is empty, set the new node as the head: new->prev = NULL;
7. If it isn't, add new node to the end: last->next = new; new->prev = last; */
t_node *add_node(t_node *head, int nbr)
{
    t_node *last;
    t_node *new;

    // Step 1: Find the last node in the linked list using last_node
    last = last_node(head);
    new = NULL;

    // Step 2: Allocate memory for a new node
    new = (t_node *)malloc(sizeof(t_node));
    if (new == NULL)
        return (NULL);

    // Step 3: Initialize the new node with the given number
    new->nbr = nbr;
    // Step 4: Set index to -1 to indicate it hasn't been assigned yet
    new->index = -1; 
    // Step 5: Initialize next to NULL, because new node is the last
    new->next = NULL;
    if (last == NULL)
    {
        // Step 6: If the list is empty, set the new node as the head
        new->prev = NULL;
        return (new);
    }
    else
    {
				// Step 7: If it isn't, add the new node to the end
        last->next = new;
        new->prev = last;
        return (head);
    }
}

/*
1. Check if the list is empty, if so return NULL
2. Traverse the list until stack->next is NULL, i.e. last node was found
3. Return a pointer to the last node found in the linked list. */
t_node *last_node(t_node *stack)
{
    // Step 1: Check if the list is empty.
    if (stack == NULL)
        return (NULL);
    
    // Step 2: Traverse the list to find the last node.
    while (stack->next) // Continue until stack->next is NULL
        stack = stack->next;
    
    // Step 3: Return a pointer to the last node found in the linked list.
    return (stack);
}

/*
1. Initialize size to 0.
2. Traverse the linked list from head to end.
3. Increment size for each node encountered.
4. Return the size of the linked list. */
int stack_size(t_node *head)
{
    int size;

    size = 0;
    while (head)
    {
        head = head->next;
        size++;
    }
    return (size);
}

/*
1. Find the minimum number in the linked list.
2. Traverse the list to find the position of the minimum number.
3. Return the position of the minimum element in the linked list. */
int position_min_nbr(t_node *head)
{
    int min;
    int i;
    t_node *tmp;

    // Step 1: Find the minimum number in the linked list
    min = head->nbr;
    tmp = head;
    while (tmp)
    {
        if (tmp->nbr < min)
            min = tmp->nbr;
        tmp = tmp->next;
    }

    // Step 2: Traverse the list to find the position of the minimum number
    i = 0;
    tmp = head;
    while (tmp)
    {
        if (tmp->nbr == min)
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (-1);
}

/*
1. Find the maximum index in the linked list.
2. Traverse the list to find the position of the maximum index.
3. Return the position of the maximum index in the linked list. */
int position_max_index(t_node *head)
{
    int max;
    int i;
    t_node *tmp;

    // Step 1: Find the maximum index in the linked list
    max = head->index;
    tmp = head;
    while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }

    // Step 2: Traverse the list to find the position of the maximum index
    i = 0;
    tmp = head;
    while (tmp)
    {
        if (tmp->index == max)
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (-1);
}
```

- `add_node`
    1. Find the last node in the linked list using the `last_node` function.
    2. Allocate memory for a new node.
    3. Initialize the new node with the given number (`nbr`).
    4. Set the `index` of the new node to -1 to indicate it hasn't been assigned yet.
    5. Initialize the `next` pointer of the new node to `NULL` because it will be the last node in the list.
    6. If the list is empty (`last` is `NULL`), set the new node as the head by setting its `prev` pointer to `NULL` and returning the new node.
    7. If the list isn't empty, link the new node to the end of the list by updating the `next` pointer of the last node and setting the `prev` pointer of the new node to the last node, then return the original head of the list.
    
    This function ensures that a new node is correctly added to the end of the linked list, with all its fields properly initialized and linked to the existing list structure. The `index` field is set to -1 as a placeholder to indicate that it needs to be assigned a proper value later.
    
- `last_node`
    1. **Check if the List is Empty**:
        - The function first checks if the input `stack` (which is a pointer to the head of the linked list) is `NULL`.
        - If `stack` is `NULL`, it means the list is empty, and the function immediately returns `NULL`.
    2. **Traverse the List to Find the Last Node**:
        - The function uses a `while` loop to traverse the linked list.
        - The condition `stack->next` checks if the current node has a next node. If it does, it moves to the next node by setting `stack` to `stack->next`.
        - This loop continues until it reaches the last node, which is identified when `stack->next` is `NULL`.

### utils_check.c

```c
#include "push_swap.h"

/* Perform data integrity checks (duplicates, valid integers).
1. Check if the stack contains any integers that are too large.
2. Check for duplicate values in the stack.
3. If any of the above checks fail, free all allocated memory,
   print an error message, and exit with an error status.
4. Check if the stack is already sorted.
5. If the stack is sorted, free all allocated memory and exit successfully. */
void perform_checks(t_node *stack_a, int ac, char **av)
{
    // Step 1: Check if the stack contains any integers that are too large.
    // Step 2: Check for duplicate values in the stack.
    if (is_too_big(stack_a) || has_duplicates(stack_a))
    {
        free_all(stack_a, ac, av); // Free all allocated memory.
        write(2, "Error\n", 6);      // Print error message to standard error.
        exit(1);                    // Exit with error status.
    }

    // Step 4: Check if the stack is already sorted.
    if (is_sorted(stack_a))
    {
        free_all(stack_a, ac, av); // Free all allocated memory.
        exit(0);                   // Exit successfully.
    }
}

/* Checks for duplicate numbers in the linked list.
1. Traverse the linked list using head.
2. For each node, clone the current node using tmp.
3. Move tmp to the next node.
4. Compare the nbr value of tmp with the nbr value of head.
5. If a duplicate is found, return 1 (true).
6. If no duplicates are found after traversing the entire list, return 0 (false). */
int has_duplicates(t_node *head)
{
    t_node *tmp;

    if (!head)
        return (0); // If the list is empty, no duplicates.

    // Step 1: Traverse the linked list using head.
    while (head->next)
    {
        tmp = head; // Step 2: Clone the current node using tmp.
        
        while (tmp->next)
        {
            tmp = tmp->next; // Step 3: Move tmp to the next node.
            
            // Step 4: Compare the nbr value of tmp with the nbr value of head.
            if (tmp->nbr == head->nbr) // Step 5: If a duplicate is found, return 1.
                return (1);
        }
        
        head = head->next; // Move head to the next node in the outer loop.
    }

    return (0); // Step 6: If no duplicates are found after traversing the entire list, return 0.
}

/* Checks if the size of the linked list is within limits.
This is necessary to assign correct indexes with the assign_index function.
1. Initialize size to 0.
2. Traverse the linked list, incrementing size.
3. If size equals INT_MAX, return 1 (true).
4. If the entire list is traversed without reaching INT_MAX, return 0 (false). */
int is_too_big(t_node *head)
{
    int size;

    size = 0;
    // Step 2: Traverse the linked list, incrementing size.
    while (head)
    {
        head = head->next;
        size++;
        if (size == INT_MAX) // Step 3: If size equals INT_MAX, return 1.
            return (1);
    }
    return (0); // Step 4: If the entire list is traversed without reaching INT_MAX, return 0.
}

/* Checks if the numbers in the linked list are in sorted order.
1. Traverse the linked list using the head node: while (head->next)
2. For each node, clone the current node using tmp: tmp = head;
3. Move tmp to the next node: tmp = tmp->next;
4. Compare the nbr value of tmp with the nbr value of head.
5. If tmp (next nbr) is smaller than head (current nbr), return 0 (false).
6. If the list is traversed without finding smaller values, return 1 (true). */
int is_sorted(t_node *head)
{
    t_node *tmp;

    // Step 1: Traverse the linked list using the head node.
    while (head->next)
    {
        // Step 2: Clone the current node using tmp.
        tmp = head;

        while (tmp->next)
        {
            tmp = tmp->next; // Step 3: Move tmp to the next node.

            // Step 4: Compare the nbr value of tmp with the nbr value of head.
            // Step 5: If tmp (next nbr) is smaller than head (current nbr), return 0 (false).
            if (head->nbr > tmp->nbr)
                return (0);
        }

        // Move head to the next node in the outer loop.
        head = head->next;
    }

    // Step 6: If the list is traversed without finding smaller values, return 1 (true).
    return (1);
}
```

### pick_sort.c

```c
#include "push_swap.h"

/* Chooses the appropriate sorting algorithm based on the size of the stack.
1. Initialize stack_b to NULL and get the size of stack_a.
2. If the size of stack_a is less than 2, return stack_a as it's already sorted.
3. Use the appropriate sorting function based on the size of stack_a:
   - For sizes 2 to 5, call the corresponding sort function from sort_small.c.
   - For sizes greater than 5, call sort_big. */
t_node *pick_sort(t_node *stack_a)
{
    t_node *stack_b;
    int size_a;

    // Step 1: Initialize stack_b to NULL and get the size of stack_a.
    stack_b = NULL;
    size_a = stack_size(stack_a);

    // Step 2: If the size of stack_a is less than 2, return stack_a as it's already sorted.
    if (size_a < 2)
        return (stack_a);
    // Step 3: Use the appropriate sorting function based on the size of stack_a.
    else if (size_a == 2)
        return (sort_2(stack_a));
    else if (size_a == 3)
        return (sort_3(stack_a));
    else if (size_a == 4)
        return (sort_4(stack_a, stack_b));
    else if (size_a == 5)
        return (sort_5(stack_a, stack_b));
    else
        return (sort_big(stack_a, stack_b));

    return (0); // This line will never be reached but is here for completeness.
}
```

### sort_small.c

```c
#include "push_swap.h"

/* Sorts two numbers in ascending order.
1. Check if the first (current) number is greater than the second (next) number
2. If true, perform the 'sa' (swap) operation to sort the two numbers.
3. Return the head of the sorted stack. */
t_node *sort_2(t_node *head_a)
{
    // Step 1: Check if the first number is greater than the second number.
    if (head_a->nbr > head_a->next->nbr)
        // Step 2: If true, perform the 'sa' (swap) operation to sort the two numbers.
        sa(&head_a);
    // Step 3: Return the head of the sorted stack.
    return (head_a);
}

/* Sorts three numbers in ascending order.
1. Assign the values of the three nodes to variables a, b, and c.
2. Use conditional statements to determine the order of the numbers and apply the appropriate operations.
3. Return the sorted stack. */
t_node	*sort_3(t_node *head_a)
{
    int a;
    int b;
    int c;

    // Step 1: Assign the values of the three nodes to variables a, b, and c.
    a = head_a->nbr;
    b = head_a->next->nbr;
    c = head_a->next->next->nbr;

    // Step 2: Use conditional statements to determine the order of the numbers and apply the appropriate operations.
    // Case 1: a < b > c > a
    if (a < b && b > c && a < c)
    {
        // Swap the first two elements and then rotate the stack.
        sa(&head_a);
        ra(&head_a);
    }
    // Case 2: a > b < c > a
    else if (a > b && b < c && a < c)
    {
        // Swap the first two elements.
        sa(&head_a);
    }
    // Case 3: a < b > c < a
    else if (a < b && b > c && a > c)
    {
        // Reverse rotate the stack.
        rra(&head_a);
    }
    // Case 4: a > b < c < a
    else if (a > b && b < c && a > c)
    {
        // Rotate the stack.
        ra(&head_a);
    }
    // Case 5: a > b > c
    else if (a > b && b > c && a > c)
    {
        // Swap the first two elements and then reverse rotate the stack.
        sa(&head_a);
        rra(&head_a);
    }

    // Step 3: Return the sorted stack.
    return (head_a);
}

/* Sorts four numbers in ascending order.
1. Perform two iterations to move the smallest two numbers to stack_b.
2. Find the position of the minimum number in stack_a and move it to the top.
3. Push the top element of stack_a to stack_b.
4. Sort the remaining two numbers in stack_a using sort_2.
5. Push the two smallest numbers back from stack_b to stack_a.
6. Return the sorted stack. */
t_node	*sort_4(t_node *head_a, t_node *head_b)
{
	int	i;
	int	min_pos;

    // Step 1: Perform two iterations to move the smallest two numbers to stack_b.
	i = 2;
	while (i--)
	{
        // Step 2: Find the position of the minimum number in stack_a and move it to the top.
		min_pos = position_min_nbr(head_a);
		if (min_pos == 1)
			ra(&head_a);
		if (min_pos == 2)
		{
			ra(&head_a);
			ra(&head_a);
		}
		if (min_pos == 3)
			rra(&head_a);
        // Step 3: Push the top element of stack_a to stack_b.
		pb(&head_a, &head_b);
	}
    // Step 4: Sort the remaining two numbers in stack_a using sort_2.
	head_a = sort_2(head_a);
    // Step 5: Push the two smallest numbers back from stack_b to stack_a.
	pa(&head_b, &head_a);
	pa(&head_b, &head_a);
    // Step 6: Return the sorted stack.
	return (head_a);
}

/* Sorts five numbers in ascending order.
1. Find the position of the minimum number in stack_a and move it to the top.
2. Push the top element of stack_a to stack_b.
3. Repeat steps 1 and 2 for the second smallest number.
4. Sort the remaining three numbers in stack_a using sort_3.
5. Push the two smallest numbers back from stack_b to stack_a.
6. Return the sorted stack. */
t_node	*sort_5(t_node *head_a, t_node *head_b)
{
	int	min_pos;

    // Step 1: Find the position of the minimum number in stack_a and move it to the top.
	min_pos = position_min_nbr(head_a);
	if (min_pos == 1 || min_pos == 2)
		ra(&head_a);
	if (min_pos == 2)
		ra(&head_a);
	if (min_pos == 3)
		rra(&head_a);
	if (min_pos == 3 || min_pos == 4)
		rra(&head_a);
    // Step 2: Push the top element of stack_a to stack_b.
	pb(&head_a, &head_b);
    
    // Step 3: Repeat steps 1 and 2 for the second smallest number.
	min_pos = position_min_nbr(head_a);
	if (min_pos == 1 || min_pos == 2)
		ra(&head_a);
	if (min_pos == 2)
		ra(&head_a);
	if (min_pos == 3)
		rra(&head_a);
	pb(&head_a, &head_b);

    // Step 4: Sort the remaining three numbers in stack_a using sort_3.
	head_a = sort_3(head_a);

    // Step 5: Push the two smallest numbers back from stack_b to stack_a.
	pa(&head_b, &head_a);
	pa(&head_b, &head_a);

    // Step 6: Return the sorted stack.
	return (head_a);
}
```

### sort_big.c

```c
#include "push_swap.h"

/* Sorts a large number of elements using a combination of sorting and indexing strategies.
1. Assign indexes to elements in stack_a.
2. Move elements from stack_a to stack_b in sorted intervals.
3. Move elements from stack_b back to stack_a in sorted order.
4. Return the sorted stack_a. */
t_node	*sort_big(t_node *head_a, t_node *head_b)
{
	// Step 1: Assign indexes to elements in stack_a.
	assign_indexes(head_a);
	
	// Step 2: Move elements from stack_a to stack_b in sorted intervals.
	atob_interval(&head_a, &head_b);
	
	// Step 3: Move elements from stack_b back to stack_a in sorted order.
	btoa_max(&head_a, &head_b);
	
	// Step 4: Return the sorted stack_a.
	return (head_a);
}

/* Assign indexes to each element in stack_a based on their value.
1. Get the size of stack_a.
2. For each element, find the maximum unindexed element and assign an index to it.
3. Repeat until all elements are indexed. */
void	assign_indexes(t_node *head_a)
{
	int		size_a;
	int		max;
	t_node	*tmp;
	t_node	*max_unindexed;

	// Step 1: Get the size of stack_a.
	size_a = stack_size(head_a);
	
	// Step 2: For each element, find the maximum unindexed element and assign an index to it.
	while (size_a--)
	{
		tmp = head_a;
		max_unindexed = head_a;
		max = INT_MIN;
		while (tmp)
		{
			if ((tmp->nbr >= max) && (tmp->index == -1))
			{
				max = tmp->nbr;
				max_unindexed = tmp;
			}
			tmp = tmp->next;
		}
		// Assign the index to the maximum unindexed element.
		max_unindexed->index = size_a;
	}
}

/* Move elements from stack_a to stack_b in sorted intervals.
1. Calculate the size of each interval.
2. For each element in stack_a, move it to stack_b if it belongs to the current interval.
3. Adjust the interval size and count as needed.
4. If the element belongs to the lower half of the interval, rotate stack_b.
5. If the element does not belong to the current interval, rotate stack_a. */
void	atob_interval(t_node **head_a, t_node **head_b)
{
	int	size_inter;
	int	count_inter;
	int	i;

	// Step 1: Calculate the size of each interval.
	size_inter = (stack_size(*head_a) / 10) + 15;
	count_inter = 1;
	i = 0;
	
	// Step 2: For each element in stack_a, move it to stack_b if it belongs to the current interval.
	while (*head_a != NULL)
	{
		if ((*head_a)->index < (count_inter * size_inter))
		{
			pb(head_a, head_b);
			// Step 4: If the element belongs to the lower half of the interval, rotate stack_b.
			if ((*head_b)->index < (count_inter * size_inter) - (size_inter / 2))
				rb(head_b);
			i++;
		}
		else
			// Step 5: If the element does not belong to the current interval, rotate stack_a.
			ra(head_a);
		
		// Step 3: Adjust the interval size and count as needed.
		if (i == (count_inter * size_inter))
			count_inter++;
	}
}

/* Move elements from stack_b back to stack_a in sorted order.
1. Find the position of the maximum index in stack_b.
2. If the maximum index is in the first half of stack_b, rotate stack_b until the maximum index is at the top, then push it to stack_a.
3. If the maximum index is in the second half of stack_b, reverse rotate stack_b until the maximum index is at the top, then push it to stack_a.
4. Repeat until all elements are moved from stack_b to stack_a. */
void	btoa_max(t_node **head_a, t_node **head_b)
{
	int	pos_max_index;

	// Step 1: Find the position of the maximum index in stack_b.
	while (*head_b != NULL)
	{
		pos_max_index = position_max_index(*head_b);
		
		// Step 2: If the maximum index is in the first half of stack_b, rotate stack_b until the maximum index is at the top, then push it to stack_a.
		if (pos_max_index <= (stack_size(*head_b) / 2))
		{
			while (pos_max_index--)
				rb(head_b);
			pa(head_b, head_a);
		}
		else
		{
			// Step 3: If the maximum index is in the second half of stack_b, reverse rotate stack_b until the maximum index is at the top, then push it to stack_a.
			pos_max_index = stack_size(*head_b) - pos_max_index;
			while (pos_max_index--)
				rrb(head_b);
			pa(head_b, head_a);
		}
	}
}
```

### ops_swap.c

```c
#include "push_swap.h"

/* Swaps the first two elements at the top of the stack.
1. If stack contains exactly 2 elements, perform a simple swap for 2 elements.
	if (stack_size(*head) == 2)
1.1 OG 2nd node becomes the current head: *head = (*head)->next;
1.2 OG 2nd node's prev assigned to OG 2nd node's next, i.e. to OG 1st node:
    (*head)->next = (*head)->prev;
1.3 NULL is assigned to OG 2nd node's prev: (*head)->prev = NULL;
1.4 The current head (OG 2nd node) is assigned to OG 1st node's prev:
    (*head)->next->prev = *head;
1.5 NULL is assigned to OG 1st node's next: (*head)->next->next = NULL;
    NULL <- OG 2nd node <-> OG 1st node -> NULL
2. If stack has more than 2 elements, perform swap for more than 2 elements: else
2.1 OG 2nd node becomes the current head: *head = (*head)->next;
2.2 OG 2nd node's next assigned to OG 1st node's next, i.e. to OG 3rd node:
    (*head)->prev->next = (*head)->next;
2.3 OG 2nd node assigned to OG 1st node's prev: (*head)->prev->prev = *head;
2.4 OG 2nd node's prev, i.e. 1st node, is assigned to OG 3rd node's prev:
    (*head)->next->prev = (*head)->prev;
2.5 OG 2nd node's prev, i.e. OG 1st node, is assigned to OG 2nd node's next:
    (*head)->next = (*head)->prev;
2.6 NULL is assigned to OG 2nd node's prev: (*head)->prev = NULL;
    NULL <- OG 2nd node <-> OG 1st node <-> OG 3rd node -> NULL */
static void swap(t_node **head)
{
    // Step 1: Check if the stack contains exactly 2 elements.
    if (stack_size(*head) == 2)
    {
        // Step 1.1: OG 2nd node becomes the current head.
        *head = (*head)->next;
        
        // Step 1.2: OG 2nd node's prev assigned to OG 2nd node's next, i.e. to OG 1st node.
        (*head)->next = (*head)->prev;
        
        // Step 1.3: NULL is assigned to OG 2nd node's prev.
        (*head)->prev = NULL;
        
        // Step 1.4: The current head (OG 2nd node) is assigned to OG 1st node's prev.
        (*head)->next->prev = *head;
        
        // Step 1.5: NULL is assigned to OG 1st node's next.
        (*head)->next->next = NULL;
        
        // Visualization: NULL <- OG 2nd node <-> OG 1st node -> NULL
    }
    else
    {
        // Step 2: Perform swap for more than 2 elements.
        
        // Step 2.1: OG 2nd node becomes the current head.
        *head = (*head)->next;
        
        // Step 2.2: OG 2nd node's next assigned to OG 1st node's next, i.e. to OG 3rd node.
        (*head)->prev->next = (*head)->next;
        
        // Step 2.3: OG 2nd node assigned to OG 1st node's prev.
        (*head)->prev->prev = *head;
        
        // Step 2.4: OG 2nd node's prev, i.e. 1st node, is assigned to OG 3rd node's prev.
        (*head)->next->prev = (*head)->prev;
        
        // Step 2.5: OG 2nd node's prev, i.e. OG 1st node, is assigned to OG 2nd node's next.
        (*head)->next = (*head)->prev;
        
        // Step 2.6: NULL is assigned to OG 2nd node's prev.
        (*head)->prev = NULL;
        
        // Visualization: NULL <- OG 2nd node <-> OG 1st node <-> OG 3rd node -> NULL
    }
}

/* Swaps the first two elements at the top of stack_a and prints "sa". */
void	sa(t_node **head)
{
	swap(head);
	ft_printf("sa\n");
}

/* Swaps the first two elements at the top of stack_b and prints "sb". */
void	sb(t_node **head)
{
	swap(head);
	ft_printf("sb\n");
}
```

### ops_rotate.c

```c
#include "push_swap.h"

/* Rotate the stack upwards (move the first element to the last position).
1. OG 2nd node becomes the current head: *head = (*head)->next;
2. OG 1st node's prev is assigned to the last node.
3. OG 1st node's next is assigned to NULL.
4. The last node's next is assigned to OG 1st node.
5. OG 2nd node's prev is assigned to NULL. 
NULL<-OG 2nd node<->OG 3rd node<->...<->OG last node<->OG 1st node->NULL*/
static void	rotate(t_node **head)
{
    // Step 1: OG 2nd node becomes the current head.
	*head = (*head)->next;
    
    // Step 2: OG 1st node's prev is assigned to the last node.
	(*head)->prev->prev = last_node(*head);
    
    // Step 3: OG 1st node's next is assigned to NULL.
	(*head)->prev->next = NULL;
    
    // Step 4: The last node's next is assigned to OG 1st node.
	(*head)->prev->prev->next = (*head)->prev;
    
    // Step 5: OG 2nd node's prev is assigned to NULL.
	(*head)->prev = NULL;
	// Visualization: NULL <- OG 2nd node <-> OG 3rd node <-> ... <-> OG last node <-> OG 1st node -> NULL
}

/* Rotate stack A upwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the rotate operation.
3. Print the operation "ra". */
void	ra(t_node **head)
{
    // Step 1: Check if the stack is empty or has only one element.
	if (!(*head))
		return ;
	if (!((*head)->next))
		return ;
    
    // Step 2: Perform the rotate operation.
	rotate(head);
    
    // Step 3: Print the operation.
	ft_printf("ra\n");
}

/* Rotate stack B upwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the rotate operation.
3. Print the operation "rb". */
void	rb(t_node **head)
{
    // Step 1: Check if the stack is empty or has only one element.
	if (!(*head))
		return ;
	if (!((*head)->next))
		return ;
    
    // Step 2: Perform the rotate operation.
	rotate(head);
    
    // Step 3: Print the operation.
	ft_printf("rb\n");
}
```

### ops_reverse_rotate.c

```c
#include "push_swap.h"

/* Reverse rotate the stack (move the last element to the first position).
1. OG last node assigned to head's prev (1st): (*head)->prev = last_node(*head);
2. Current head assigned to OG last node's next: (*head)->prev->next = *head;
3. NULL assigned to OG 2nd to last node's next: (*head)->prev->prev->next = NULL;
4. NULL assigned to OG last node's prev: (*head)->prev->prev = NULL;
5. The head is updated to point to the last node: *head = (*head)->prev */
static void	reverse_rotate(t_node **head)
{
    // Step 1: OG last node assigned to head's prev (1st).
    (*head)->prev = last_node(*head);
    
    // Step 2: Current head assigned to OG last node's next.
    (*head)->prev->next = *head;
    
    // Step 3: NULL assigned to OG 2nd to last node's next.
    (*head)->prev->prev->next = NULL;
    
    // Step 4: NULL assigned to OG last node's prev.
    (*head)->prev->prev = NULL;
    
    // Step 5: The head is updated to point to the last node.
    *head = (*head)->prev;

    // Visualization: NULL <- OG last node <-> OG 1st node <-> OG 2nd node -> NULL
}

/* Reverse rotate stack A downwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the reverse rotate operation.
3. Print the operation "rra". */
void	rra(t_node **head)
{
    // Step 1: Check if the stack is empty or has only one element.
	if (!(*head))
		return;
	if (!((*head)->next))
		return;
    
    // Step 2: Perform the reverse rotate operation.
	reverse_rotate(head);
    
    // Step 3: Print the operation.
	ft_printf("rra\n");
}

/* Reverse rotate stack B downwards.
1. Check if the stack is empty or has only one element.
2. If not, perform the reverse rotate operation.
3. Print the operation "rrb". */
void	rrb(t_node **head)
{
    // Step 1: Check if the stack is empty or has only one element.
	if (!(*head))
		return;
	if (!((*head)->next))
		return;
    
    // Step 2: Perform the reverse rotate operation.
	reverse_rotate(head);
    
    // Step 3: Print the operation.
	ft_printf("rrb\n");
}
```

### ops_push.c

```c
#include "push_swap.h"

/* Push the top element from the source stack to the destination stack.
1. If destination stack is empty, perform initial push:
1.1 Move head of src to the next node: *src = (*src)->next;
1.2 OG 1st node of src becomes the head of dst: *dst = (*src)->prev;
1.3 NULL is assigned to OG 1st node of dst's next: (*dst)->next = NULL;
1.4 NULL is assigned to OG 1st node of dst's prev: (*dst)->prev = NULL;
1.5 NULL is assigned to the new head of src's prev: (*src)->prev = NULL;
	NULL <- OG 1st node of dst (new head) -> NULL
2. If src stack has only one element, push it to dst:
2.1 OG 1st node's next assigned to dst: (*src)->next = *dst;
2.2 OG 1st node becomes dst's prev: (*dst)->prev = *src;
2.3 OG 1st node becomes the new head of dst: *dst = *src;
2.4 NULL is assigned to src: *src = NULL;
	OG 1st node of dst (new head) <-> OG 1st node of dst's next -> NULL
3. If src stack has more than one element, perform general push:
3.1 Move head of src to the next node: *src = (*src)->next;
3.2 OG 2nd node's next assigned to dst: (*src)->prev->next = *dst;
3.3 OG 1st node of src becomes the new head of dst: *dst = (*src)->prev;
3.4 dst's prev assigned to dst: (*dst)->next->prev = *dst;
3.5 NULL is assigned to the new head of src's prev: (*src)->prev = NULL;
NULL<-OG 1st node (new head)<->OG 2nd node<->...<->OG last node ->NULL */
static void push(t_node **src, t_node **dst)
{
    if (*dst == NULL)
    {
        // Step 1.1: Move head of src to the next node.
        *src = (*src)->next;
        
        // Step 1.2: OG 1st node of src becomes the head of dst.
        *dst = (*src)->prev;
        
        // Step 1.3: NULL is assigned to OG 1st node of dst's next.
        (*dst)->next = NULL;
        
        // Step 1.4: NULL is assigned to OG 1st node of dst's prev.
        (*dst)->prev = NULL;
        
        // Step 1.5: NULL is assigned to the new head of src's prev.
        (*src)->prev = NULL;

        // Visualization: NULL <- OG 1st node of dst (new head) -> NULL
    }
    else if ((*src)->next == NULL)
    {
        // Step 2.1: OG 1st node's next assigned to dst.
        (*src)->next = *dst;
        
        // Step 2.2: OG 1st node becomes dst's prev.
        (*dst)->prev = *src;
        
        // Step 2.3: OG 1st node becomes the new head of dst.
        *dst = *src;
        
        // Step 2.4: NULL is assigned to src.
        *src = NULL;

        // Visualization: OG 1st node of dst (new head) <-> OG 2nd node of dst <-> ... <-> OG last node of dst -> NULL
    }
    else
    {
        // Step 3.1: Move head of src to the next node.
        *src = (*src)->next;
        
        // Step 3.2: OG 2nd node's next assigned to dst.
        (*src)->prev->next = *dst;
        
        // Step 3.3: OG 1st node of src becomes the new head of dst.
        *dst = (*src)->prev;
        
        // Step 3.4: dst's prev assigned to dst.
        (*dst)->next->prev = *dst;
        
        // Step 3.5: NULL is assigned to the new head of src's prev.
        (*src)->prev = NULL;

        // Visualization: NULL <- OG 1st node of dst (new head) <-> OG 2nd node of dst <-> ... <-> OG last node of dst -> NULL
    }
}

/* Push the top element from stack_a to stack_b and print "pb".
1. Perform the push operation.
2. Print the operation "pb". */
void pb(t_node **head_a, t_node **head_b)
{
    // Step 1: Perform the push operation.
    push(head_a, head_b);
    
    // Step 2: Print the operation.
    ft_printf("pb\n");
}

/* Push the top element from stack_b to stack_a and print "pa".
1. Perform the push operation.
2. Print the operation "pa". */
void pa(t_node **head_b, t_node **head_a)
{
    // Step 1: Perform the push operation.
    push(head_b, head_a);
    
    // Step 2: Print the operation.
    ft_printf("pa\n");
}
```

## Example

### Scenario 1: Multiple Arguments

```bash
./push_swap 3 2 5 1 4
```

- `ac = 6`
- `av = ["./push_swap", "3", "2", "5", "1", "4"]`
- `i = 1` to skip the program name.

### Scenario 2: Single Argument

```bash
./push_swap "3 2 5 1 4"
```

- `ac = 2`
- `av = ["./push_swap", "3 2 5 1 4"]`
- `ft_split(av[1], ' ')` produces a new array: `["3", "2", "5", "1", "4"]`
- `i = 0` to start processing from the first element of the split array.

### Understanding the While Loop

```c
while (av[i])
    stack_a = add_node(stack_a, custom_atoi(av[i++], stack_a, ac, av));
```

1. **`av[i]`**: Represents the current argument being processed.
2. **`custom_atoi(av[i++], stack_a, ac, av)`**:
    - **Purpose**: Converts the current argument (`av[i]`) from a string to an integer, checking for errors and incrementing `i`.
    - **Parameters**:
        - `av[i++]`: The current argument string.
        - `stack_a`, `ac`, `av`: These are passed to `custom_atoi` to handle errors appropriately (freeing memory and exiting if necessary).
3. **`add_node(stack_a, ...)`**:
    - **Purpose**: Adds a new node to the linked list `stack_a` with the integer value returned by `custom_atoi`.
    - **Parameters**:
        - `stack_a`: The current head of the linked list.
        - `custom_atoi(...)`: The integer value to be added to the list.

### Step-by-Step Execution

Let's walk through the example `./push_swap 3 2 5 1 4`.

1. **Initial Values**:
    - `ac = 6`
    - `av = ["./push_swap", "3", "2", "5", "1", "4"]`
    - `i = 1`
    - `stack_a = NULL`
2. **First Iteration**:
    - `av[1]` is "3".
    - `stack_a = add_node(stack_a, custom_atoi("3", stack_a, ac, av))`.
3. **Inside `custom_atoi`**:
    - Converts "3" to integer 3, returns 3.
    - `custom_atoi` does not modify `stack_a` directly; it uses it only for error handling.
4. **Inside `add_node`**:
    - `add_node(NULL, 3)` is called.
    - A new node with `nbr = 3` is created and becomes the head of `stack_a`.
5. **Update Values**:
    - `i = 2`
    - `stack_a` now points to the node with `nbr = 3`.
6. **Second Iteration**:
    - `av[2]` is "2".
    - `stack_a = add_node(stack_a, custom_atoi("2", stack_a, ac, av))`.
7. **Inside `custom_atoi`**:
    - Converts "2" to integer 2, returns 2.
8. **Inside `add_node`**:
    - `add_node(stack_a, 2)` is called.
    - A new node with `nbr = 2` is created and added to the end of the list.
9. **Update Values**:
    - `i = 3`
    - `stack_a` now points to the head node with `nbr = 3`, and this node points to the next node with `nbr = 2`.

### Visual Representation

```bash
Initial: stack_a = NULL, i = 1

1st Iteration:
  av[1] = "3"
  custom_atoi("3") -> 3
  add_node(NULL, 3) -> stack_a = 3

2nd Iteration:
  av[2] = "2"
  custom_atoi("2") -> 2
  add_node(3, 2) -> stack_a = 3 -> 2

3rd Iteration:
  av[3] = "5"
  custom_atoi("5") -> 5
  add_node(3 -> 2, 5) -> stack_a = 3 -> 2 -> 5

4th Iteration:
  av[4] = "1"
  custom_atoi("1") -> 1
  add_node(3 -> 2 -> 5, 1) -> stack_a = 3 -> 2 -> 5 -> 1

5th Iteration:
  av[5] = "4"
  custom_atoi("4") -> 4
  add_node(3 -> 2 -> 5 -> 1, 4) -> stack_a = 3 -> 2 -> 5 -> 1 -> 4

Final: stack_a = 3 -> 2 -> 5 -> 1 -> 4

```