/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int n;

// DFS function
void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            printf("\nGoing from %d → %d\n", v, i);
            dfs(i);
        }
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    // input adjacency matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal:\n");

    dfs(start);

    printf("\n");

    return 0;
}