/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// insert element
void insert(int x) {
    pq[size++] = x;
    printf("Inserted %d\n", x);
}

// delete highest priority (smallest element)
void deleteElement() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    printf("%d\n", pq[minIndex]);

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// peek highest priority
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int min = pq[0];

    for (int i = 1; i < size; i++) {
        if (pq[i] < min) {
            min = pq[i];
        }
    }

    printf("%d\n", min);
}

int main() {

    int n, value;
    char operation[10];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        }

        else if (strcmp(operation, "delete") == 0) {
            deleteElement();
        }

        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}