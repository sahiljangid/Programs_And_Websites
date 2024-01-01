#include <stdio.h>
#include <stdlib.h>

#define max 100
#define INF 9999

// Structure to represent the graph
struct Graph
{
    int numVertices;
    int adjacencyMatrix[max][max]; // Matrix to represent presence of edges
    int weightMatrix[max][max];    // Matrix to represent weights of edges
};

// Function to create an undirected weighted graph with a given number of vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize the matrices with INF for absence of edges
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0; // 0 represents absence of edge
            graph->weightMatrix[i][j] = INF;
        }
    }

    return graph;
}

// Function to add a weighted undirected edge to the graph
void addWeightedUndirectedEdge(struct Graph *graph, int src, int dest, int weight)
{
    // Adding an undirected edge between src and dest with the same weight
    graph->adjacencyMatrix[src][dest] = 1; // 1 represents presence of edge
    graph->adjacencyMatrix[dest][src] = 1; // For undirected graph, both directions are considered
    graph->weightMatrix[src][dest] = weight;
    graph->weightMatrix[dest][src] = weight;
}

// Function to display the adjacency matrix and weight matrix of the weighted graph
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

    printf("\nWeight Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->weightMatrix[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d   ", graph->weightMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Driver program
int main()
{
    // Create an undirected weighted graph with 5 vertices
    struct Graph *graph = createGraph(5);

    // Add weighted undirected edges
    addWeightedUndirectedEdge(graph, 0, 1, 2);
    addWeightedUndirectedEdge(graph, 0, 3, 1);
    addWeightedUndirectedEdge(graph, 1, 2, 4);
    addWeightedUndirectedEdge(graph, 1, 4, 5);
    addWeightedUndirectedEdge(graph, 2, 3, 3);
    addWeightedUndirectedEdge(graph, 3, 4, 7);

    // Display the undirected weighted graph
    displayGraph(graph);

    // Free allocated memory
    free(graph);

    return 0;
}
