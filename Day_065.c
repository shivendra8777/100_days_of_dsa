/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
Output:- YES or NO*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX];
    int visited[MAX];
} Graph;

// Create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function to detect cycle
int dfsCycle(Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    Node* temp = graph->adjLists[v];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!graph->visited[adjVertex]) {
            if (dfsCycle(graph, adjVertex, v))
                return 1;
        }
        else if (adjVertex != parent) {
            return 1; // Cycle detected
        }

        temp = temp->next;
    }

    return 0;
}

// Function to check cycle in graph
int hasCycle(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (dfsCycle(graph, i, -1))
                return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    int vertices, edges;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    Graph* graph = createGraph(vertices);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}