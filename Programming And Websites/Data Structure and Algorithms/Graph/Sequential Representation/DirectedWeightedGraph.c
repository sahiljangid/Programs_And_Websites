#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;     
    int weight;   // Weight of the edge
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

// Function to create a new node
struct Node* createNode(int data, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;   // Renamed from dest
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    
    // Allocate memory for the adjacency list
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add a weighted directed edge to the graph
void addWeightedEdge(struct Graph* graph, int src, int data, int weight) {
    // Create a new node for the destination vertex with the given weight
    struct Node* newNode = createNode(data, weight);
    
    // Add the new node to the source vertex's adjacency list
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Function to print the adjacency list representation of the weighted graph
void printWeightedGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* current = graph->adjacencyList[i];
        printf("Adjacency list for vertex %d: ", i);
        while (current) {
            printf("(%d, %d) -> ", current->data, current->weight);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Driver program to test the graph implementation
int main() {
    // Create a directed weighted graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add weighted edges to the graph
    addWeightedEdge(graph, 0, 1, 2);
    addWeightedEdge(graph, 0, 4, 1);
    addWeightedEdge(graph, 1, 2, 4);
    addWeightedEdge(graph, 1, 3, 3);
    addWeightedEdge(graph, 2, 3, 1);
    addWeightedEdge(graph, 3, 4, 5);

    // Print the adjacency list representation of the weighted graph
    printWeightedGraph(graph);

    return 0;
}
