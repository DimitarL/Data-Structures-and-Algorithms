# Task 1 - Attacking Vigorously the Leaderboard

Complete the balanced AVL tree by performing the following operations:
1. Add an item
2. Remove an element

It is forbidden to use stl::map!!!

- Input Format

When you use add if the number already exists, write "X already added" and a new line then (in place of X the given number itself should be displayed)

If remove if the number does not exist, write "X not found to remove" and a new line then (in place of X the given number itself should be displayed)

Constraints

1 <= N <= 100 000

int.MIN_VALUE <= number <= int.MAX_VALUE

- Output Format

contains operation - type "yes" or "no" depending on whether the given number is contained in the tree.

In a print operation, type the current state of the tree in the Left-Root-Right format with the spacing between the elements.

Notes! cout << fixed; always returns up to 6 decimal places.


- Sample Input 0

7
add 58
add 98
contains 58
add 52
contains 23
add 23
print

- Sample Output 0

yes
no
23.000000 52.000000 58.000000 98.000000 

- Sample Input 1

16                                                                                                                                        
add 8.43
add 5.83
add 7.66
add 1.92
remove 7.66
add 4.47
add -2.76
contains 7.23
add -1.64
remove 5.49
add 4.66
add 3.04
add 4.47
contains 8.43
add 7.34
print

- Sample Output 1

no
5.490000 not found to remove
4.470000 already added
yes
-2.760000 -1.640000 1.920000 3.040000 4.470000 4.660000 5.830000 7.340000 8.430000 

