/*Problem Statement
Given an array of integers containing both positive and negative values, 
find the length of the longest contiguous subarray whose sum is equal to zero.
*/
#include <stdio.h>

#define MAX 100

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0;
    int maxLen = 0;

    // store prefix sums
    int sum[MAX];
    int index[MAX];
    int size = 0;

    for(int i = 0; i < n; i++)
    {
        prefix += arr[i];
        printf("Index %d → Element %d → Prefix Sum = %d\n", i, arr[i], prefix);

        // if prefix sum is 0
        if(prefix == 0)
        {
            maxLen = i + 1;
        }

        int found = 0;

        // check if prefix seen before
        for(int j = 0; j < size; j++)
        {
            if(sum[j] == prefix)
            {
                int length = i - index[j];
                printf("Repeat sum found → Length = %d\n", length);

                if(length > maxLen)
                    maxLen = length;

                found = 1;
                break;
            }
        }

        // store new prefix sum
        if(!found)
        {
            sum[size] = prefix;
            index[size] = i;
            size++;
        }
    }

    printf("\nLongest subarray length with sum 0: %d\n", maxLen);

    return 0;
}