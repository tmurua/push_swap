# push_swap

## Overview

**push_swap** is a sorting algorithm implementation project with the goal of sorting a stack of integers using the minimal number of operations. The program efficiently handles input validation, supports small and large datasets, and adheres to strict operation limits as specified in the project guidelines.

## Features

- **Sorting:** Implements a chunk-based sorting algorithm.
- **Input Validation:** Detects and handles invalid inputs, including non-integer values, duplicates, and integer overflows.
- **Minimal Operations:** Strives to sort the stack with the fewest possible moves. The goal was to sort 100 random numbers in fewer than 700 operations.
- **Optimized for Small Stacks:** Uses specialized sorting algorithms for stacks with 2 to 5 elements.

## Installation

1. **Clone the Repository:**
    
    ```bash
    git clone https://github.com/tmurua/push_swap.git
    
    ```
    
2. **Navigate to the Project Directory:**
    
    ```bash
    cd push_swap
    ```
    
3. **Compile the Program:**
    
    ```bash
    make
    ```
    

## Usage

```bash
./push_swap <numbers>
```

### Examples

- **Basic Sorting:**
    
    ```bash
    ./push_swap 3 2 1
    ```
    
- **Handling Invalid Input:**
    
    ```bash
    ./push_swap 1 2 three
    # Output: Error
    ```
    
- **Empty Input:**
    
    ```bash
    ./push_swap ""
    # Output: Error
    ```
    

## Supported Operations

- **Swap:** `sa`, `sb`, `ss`
- **Push:** `pa`, `pb`
- **Rotate:** `ra`, `rb`, `rr`
- **Reverse Rotate:** `rra`, `rrb`, `rrr`

## Error Handling

The program validates all inputs and will display `Error` followed by a newline (`\n`) on `stderr` for any of the following cases:

- Non-integer inputs
- Duplicate numbers
- Integer overflow/underflow
- Invalid argument formats (e.g., multiple signs, empty strings)

## Testing

A comprehensive test suite is available to validate the program's functionality and error handling. The tester can be found [here](https://github.com/gemartin99/Push-Swap-Tester).

To run the tests:

1. **Ensure the Tester is Cloned:**
    
    ```bash
    git clone https://github.com/gemartin99/Push-Swap-Tester.git
    
    ```
    
2. **Navigate to the Tester Directory:**
    
    ```bash
    cd Push-Swap-Tester
    ```
    
3. **Run the Test Script:**
    
    ```bash
    bash push_swap_test_linux.sh
    ```
    

## Dependencies

- **Libft:** A custom C library required for the project. Included in the `libft` directory.

## Author

**Tom Murua**

Email: tommurua@gmail.com

GitHub: [github.com/tmurua](https://github.com/tmurua/push_swap)

LinkedIn: [linkedin.com/in/tmurua](https://linkedin.com/in/tmurua)
