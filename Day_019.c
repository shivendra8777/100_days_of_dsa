/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero
*/
#include <stdio.h>
#include <stdlib.h>   // for abs()

int main() {
    int n, i, j;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = arr[0] + arr[1];
    int first = arr[0], second = arr[1];

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                first = arr[i];
                second = arr[j];
            }
        }
    }

    printf("Pair closest to zero: %d %d\n", first, second);

    return 0;
}
