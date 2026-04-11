/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

// Edge structure
struct Edge {
    int u, v, w;
};

int main() {
    int n, m, i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Edge edges[MAX];

    printf("Enter edges (u v w):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[MAX];

    // Step 1: Initialize distances
    for(i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Relax edges (n-1 times)
    for(i = 1; i <= n - 1; i++) {
        printf("\nIteration %d:\n", i);

        for(j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                printf("Updated dist[%d] = %d\n", v, dist[v]);
            }
        }
    }

    // Step 3: Check for negative cycle
    for(j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("\nNEGATIVE CYCLE DETECTED!\n");
            return 0;
        }
    }

    // Step 4: Print shortest distances
    printf("\nShortest distances from source %d:\n", src);
    for(i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}
