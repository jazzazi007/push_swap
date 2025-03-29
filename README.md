# Push Swap

A highly efficient sorting algorithm project implemented in C that sorts data on a stack, with a limited set of instructions, using the smallest possible number of moves.

## Overview

Push_swap is a sorting algorithm that uses two stacks (A and B) and a set of operations to sort numbers in ascending order. The project implements the "Turk algorithm" approach which provides an efficient way to sort the numbers with minimal operations.

## Algorithm

The implementation uses an optimized version of the Turk algorithm with the following key steps:

1. Initialize stack A with input numbers and keep stack B empty
2. Find the cheapest node to push from A to B based on:
   - Position in stack A
   - Target position in stack B
   - Total cost of moves
3. Push nodes to stack B until only 3 numbers remain in A
4. Sort the remaining 3 numbers in stack A
5. Find optimal target positions to push numbers back to A
6. Push all numbers back to A in sorted order
7. Rotate stack A to put the smallest number on top

### Sorting Operations

The program uses the following operations:
- `sa`: Swap first two elements of stack A
- `sb`: Swap first two elements of stack B
- `ss`: sa and sb at the same time
- `pa`: Push top element from stack B to stack A
- `pb`: Push top element from stack A to stack B
- `ra`: Rotate stack A up by one
- `rb`: Rotate stack B up by one
- `rr`: ra and rb at the same time
- `rra`: Rotate stack A down by one
- `rrb`: Rotate stack B down by one 
- `rrr`: rra and rrb at the same time

## Usage

```bash
# Compile
make

# Run with numbers as arguments
./push_swap 5 2 3 1 4
