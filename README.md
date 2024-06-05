# push_swap

### Overview

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