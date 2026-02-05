/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces*/
#include <stdio.h>

int main() {
    int p, q;

    // Input size of first server log
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    int log1[p];

    // Input elements of first server log
    printf("Enter arrival times for server log 1 (sorted):\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Input size of second server log
    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    int log2[q];

    // Input elements of second server log
    printf("Enter arrival times for server log 2 (sorted):\n");
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;

    // Merging both logs
    printf("\nMerged chronological log:\n");

    // Compare elements from both logs
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // Print remaining elements of server log 1 (if any)
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    // Print remaining elements of server log 2 (if any)
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
