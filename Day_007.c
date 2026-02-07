/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number
*/
#include <stdio.h>

/* Recursive function to find nth Fibonacci number */
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n, result;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    result = fib(n);

    printf("The %dth Fibonacci number is: %d\n", n, result);

    return 0;
}
