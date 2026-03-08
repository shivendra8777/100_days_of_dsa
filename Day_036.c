/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0, rear = 0;

// enqueue
void enqueue(int value)
{
    queue[rear] = value;
    rear = (rear + 1) % MAX;

    printf("Inserted %d into queue\n", value);
}

// dequeue
void dequeue()
{
    printf("Removed %d from queue\n", queue[front]);
    front = (front + 1) % MAX;
}

// display
void display()
{
    printf("Queue elements from front to rear: ");

    int i = front;
    int count = 0;

    while (count < MAX)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
        count++;
    }

    printf("\n");
}

int main()
{
    int n, m, value;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}