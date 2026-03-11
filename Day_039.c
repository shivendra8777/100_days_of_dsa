/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the
root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

// swap two numbers
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// insert element
void insert(int value) {
  printf("Inserting %d into heap\n", value);

  heap[size] = value;
  int i = size;
  size++;

  // move element up to maintain min heap
  while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
    swap(&heap[(i - 1) / 2], &heap[i]);
    i = (i - 1) / 2;
  }
}

// peek (see smallest element)
void peek() {
  if (size == 0) {
    printf("-1\n");
    return;
  }

  printf("Smallest element is: %d\n", heap[0]);
}

// extract minimum
void extractMin() {
  if (size == 0) {
    printf("-1\n");
    return;
  }

  printf("Removed smallest element: %d\n", heap[0]);

  heap[0] = heap[size - 1];
  size--;

  int i = 0;

  // move element down
  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < size && heap[left] < heap[smallest])
      smallest = left;

    if (right < size && heap[right] < heap[smallest])
      smallest = right;

    if (smallest != i) {
      swap(&heap[i], &heap[smallest]);
      i = smallest;
    } else
      break;
  }
}

int main() {
  int n, value;
  char operation[20];

  printf("Enter number of operations: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter operation: ");
    scanf("%s", operation);

    if (strcmp(operation, "insert") == 0) {
      scanf("%d", &value);
      insert(value);
    } else if (strcmp(operation, "peek") == 0) {
      peek();
    } else if (strcmp(operation, "extractMin") == 0) {
      extractMin();
    }
  }

  return 0;
}