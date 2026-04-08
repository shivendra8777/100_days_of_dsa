/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// Function to push into stack
void push(int node) {
    stack[++top] = node;
    printf("Pushed %d into stack\n", node);
}

// DFS function
void dfs(int node) {
    visited[node] = 1;
    printf("Visited node %d\n", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            printf("Going to node %d from node %d\n", i, node);
            dfs(i);
        }
    }

    push(node);
}

// Topological Sort using DFS
void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("\nStarting DFS from node %d\n", i);
            dfs(i);
        }
    }

    printf("\nTopological Order (DFS Method): ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}