/*Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.*/

#include <stdio.h>

// lower bound
int lowerBound(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        printf("LB Check mid=%d value=%d\n", mid, arr[mid]);

        if(arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

// upper bound
int upperBound(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        printf("UB Check mid=%d value=%d\n", mid, arr[mid]);

        if(arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, x;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target x: ");
    scanf("%d", &x);

    printf("\nFinding Lower Bound...\n");
    int lb = lowerBound(arr, n, x);

    printf("\nFinding Upper Bound...\n");
    int ub = upperBound(arr, n, x);

    printf("\nResult:\n");
    printf("Lower Bound Index = %d\n", lb);
    printf("Upper Bound Index = %d\n", ub);

    return 0;
}