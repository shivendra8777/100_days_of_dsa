/*Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. 
The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.*/

#include <stdio.h>

#define MAX 100
#define INF 9999

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[MAX][MAX];

    printf("Enter adjacency matrix (-1 for no edge):\n");

    // input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);

            if(dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }

    printf("\nRunning Floyd-Warshall...\n");

    // algorithm
    for(int k = 0; k < n; k++)
    {
        printf("\nUsing node %d as intermediate\n", k);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    printf("Updating dist[%d][%d] from %d to %d\n",
                           i, j, dist[i][j], dist[i][k] + dist[k][j]);

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nFinal Shortest Distance Matrix:\n");

    // output
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}