/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated
*/
#include <stdio.h>

int main() {
    int n, pos, x;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Check for valid position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Insertion not possible.\n");
        return 0;
    }

    printf("Shifting elements to the right to make space...\n");

    // Shift elements to the right
    for (int i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    // Insert the element
    a[pos - 1] = x;

    printf("Updated array is:\n");

    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
