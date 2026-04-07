/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Graph using adjacency matrix
int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

// DFS function to detect cycle
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    printf("Visiting node: %d\n", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            // If not visited, recurse
            if (!visited[i]) {
                if (dfs(i))
                    return 1;
            }
            // If already in recursion stack → cycle
            else if (recStack[i]) {
                printf("Cycle detected at node: %d\n", i);
                return 1;
            }
        }
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

// Function to check cycle in graph
int isCycle() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed graph
    }

    if (isCycle())
        printf("\nYES - Cycle exists in the graph\n");
    else
        printf("\nNO - No cycle in the graph\n");

    return 0;
}