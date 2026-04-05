/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = 0, rear = -1;
int n;

// enqueue
void enqueue(int x)
{
    rear++;
    queue[rear] = x;
    printf("Inserted %d into queue\n", x);
}

// dequeue
int dequeue()
{
    int x = queue[front];
    front++;
    printf("Removed %d from queue\n", x);
    return x;
}

// BFS function
void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal:\n");

    while(front <= rear)
    {
        int current = dequeue();
        printf("Visited: %d\n", current);

        for(int i = 0; i < n; i++)
        {
            if(adj[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}