#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices in the graph
#define max 100

// Structure to represent the graph
struct Graph
{
    int numVertices;
    int adjacencyMatrix[max][max];
};

// Function to create an undirected graph with a given number of vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Adding an edge between src and dest
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

// Function to display the adjacency matrix of the graph
void displayGraph(struct Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Driver program
int main()
{
    // Create a graph with 5 vertices
    struct Graph *graph = createGraph(5);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Display the graph
    displayGraph(graph);

    // Free allocated memory
    free(graph);

    return 0;
}
