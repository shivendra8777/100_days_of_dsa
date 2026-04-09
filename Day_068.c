/* Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

// Function to perform Kahn's Algorithm
void kahnTopoSort() {
    int front = 0, rear = -1;

    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
        printf("Indegree of node %d = %d\n", i, indegree[i]);
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
            printf("Node %d added to queue (indegree 0)\n", i);
        }
    }

    printf("\nTopological Order (Kahn's Method): ");

    // Step 3: Process queue
    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                printf("\nReduced indegree of node %d to %d", i, indegree[i]);

                if (indegree[i] == 0) {
                    queue[++rear] = i;
                    printf("\nNode %d added to queue", i);
                }
            }
        }
    }
}

// Main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    kahnTopoSort();

    return 0;
}