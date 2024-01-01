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

// Function to create a directed graph with a given number of vertices
struct Graph *createGraph(int Vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = Vertices;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < Vertices; i++)
    {
        for (int j = 0; j < Vertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add a directed edge to the graph
void addDirectedEdge(struct Graph *graph, int src, int dest)
{
    // Adding a directed edge from src to dest
    graph->adjacencyMatrix[src][dest] = 1;
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
    // Create a directed graph with 5 vertices
    struct Graph *graph = createGraph(5);

    // Add directed edges
    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 0, 4);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 1, 3);
    addDirectedEdge(graph, 1, 4);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 4);

    // Display the graph
    displayGraph(graph);

    // Free allocated memory
    free(graph);

    return 0;
}
