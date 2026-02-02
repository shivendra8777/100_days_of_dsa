/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated
*/
#include <stdio.h>

int main() {
    int n, pos;

    // Ask for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);


    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

  
    printf("Array after deleting element at position %d: ", pos);
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
