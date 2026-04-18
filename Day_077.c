/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n, m;

// DFS function
void dfs(int v)
{
    visited[v] = 1;
    printf("Visited node: %d\n", v);

    for(int i = 1; i <= n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            printf("Going from %d → %d\n", v, i);
            dfs(i);
        }
    }
}

int main()
{
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            adj[i][j] = 0;

    printf("Enter edges:\n");
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    printf("\nStarting DFS from node 1...\n");

    dfs(1);

    // count visited nodes
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 1)
            count++;
    }

    printf("\nTotal visited nodes: %d\n", count);

    if(count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}