/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.
*/
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

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX], visited[MAX] = {0};

    // initialize distances
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;

    printf("\nRunning Dijkstra...\n");

    for(int count = 1; count <= n; count++)
    {
        int min = INF, u = -1;

        // find minimum distance vertex
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;
        printf("Selected node %d with distance %d\n", u, dist[u]);

        // update neighbors
        for(int v = 1; v <= n; v++)
        {
            if(!visited[v] && cost[u][v] != INF)
            {
                if(dist[u] + cost[u][v] < dist[v])
                {
                    printf("Updating distance of %d from %d to %d\n",
                           v, dist[v], dist[u] + cost[u][v]);

                    dist[v] = dist[u] + cost[u][v];
                }
            }
        }
    }

    printf("\nShortest distances:\n");
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    printf("\n");

    return 0;
}