#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Graph
{
    int vertices;
    struct Node **adjacencyList;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
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

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);

    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
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
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *current = graph->adjacencyList[i];
        printf("Adjacency list for vertex %d: ", i);

        while (current)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    struct Graph *graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);

    printf("Graph before deletion:\n");
    printGraph(graph);

    deleteNode(graph, 2);
    deleteEdge(graph, 1, 3);

    printf("\nGraph after deletion:\n");
    printGraph(graph);

    free(graph->adjacencyList);
    free(graph);

    return 0;
}
