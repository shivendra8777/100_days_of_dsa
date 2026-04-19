/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.*/

#include <stdio.h>

#define MAX 100
#define INF 9999

int main()
{
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int cost[MAX][MAX];

    // initialize matrix
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cost[i][j] = INF;

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        cost[u][v] = w;
        cost[v][u] = w; // undirected
    }

    int visited[MAX] = {0};
    visited[1] = 1; // start from node 1

    int edges = 0;
    int total = 0;

    printf("\nBuilding MST using Prim's Algorithm...\n");

    while(edges < n - 1)
    {
        int min = INF, a = -1, b = -1;

        for(int i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(int j = 1; j <= n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a != -1 && b != -1)
        {
            printf("Selected edge: %d - %d (weight %d)\n", a, b, min);

            visited[b] = 1;
            total += min;
            edges++;
        }
    }

    printf("\nTotal weight of MST: %d\n", total);

    return 0;
}