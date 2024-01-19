#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int weight;
    struct Node *next;
};

struct Graph
{
    int vertices;
    struct Node **adjacencyList;
};

struct Node *createNode(int data, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node **)malloc(vertices * sizeof(struct Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addUndirectedWeightedEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void deleteNode(struct Graph *graph, int vertex)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *current = graph->adjacencyList[i];
        struct Node *prev = NULL;

        while (current)
        {
            if (current->data == vertex)
            {
                if (prev == NULL)
                {
                    struct Node *temp = current;
                    graph->adjacencyList[i] = current->next;
                    free(temp);
                    current = graph->adjacencyList[i];
                }
                else
                {
                    struct Node *temp = current;
                    prev->next = current->next;
                    current = current->next;
                    free(temp);
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }

    free(graph->adjacencyList[vertex]);
    graph->adjacencyList[vertex] = NULL;
}

void deleteEdge(struct Graph *graph, int src, int dest)
{

    struct Node *current = graph->adjacencyList[src];
    struct Node *prev = NULL;

    while (current)
    {
        if (current->data == dest)
        {
            if (prev == NULL)
            {
                graph->adjacencyList[src] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            break;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    current = graph->adjacencyList[dest];
    prev = NULL;

    while (current)
    {
        if (current->data == src)
        {
            if (prev == NULL)
            {
                graph->adjacencyList[dest] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            break;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void printWeightedGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *current = graph->adjacencyList[i];
        printf("Adjacency list for vertex %d: ", i);
        while (current)
        {
            printf("(%d, %d) -> ", current->data, current->weight);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    struct Graph *graph = createGraph(5);

    addUndirectedWeightedEdge(graph, 0, 1, 2);
    addUndirectedWeightedEdge(graph, 0, 4, 1);
    addUndirectedWeightedEdge(graph, 1, 2, 4);
    addUndirectedWeightedEdge(graph, 1, 3, 3);
    addUndirectedWeightedEdge(graph, 2, 3, 1);
    addUndirectedWeightedEdge(graph, 3, 4, 5);

    printf("Graph before deletion:\n");
    printWeightedGraph(graph);

    deleteNode(graph, 2);
    deleteEdge(graph, 1, 3);

    printf("\nGraph after deletion:\n");
    printWeightedGraph(graph);

    free(graph->adjacencyList);
    free(graph);

    return 0;
}
