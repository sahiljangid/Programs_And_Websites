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

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

int isQueueFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue *queue, int item)
{
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isQueueEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

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

    newNode = createNode(src);
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

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *current = graph->adjacencyList[i];
        printf("Adjacency list for vertex %d: ", i);

        if (current == NULL)
        {
            printf("NULL");
        }
        else
        {
            while (current)
            {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL");
        }

        printf("\n");
    }
}

void BFS(struct Graph *graph, int startVertex)
{
    struct Queue *queue = createQueue(graph->vertices);
    int *visited = (int *)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; i++)
    {
        visited[i] = 0;
    }

    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isQueueEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node *current = graph->adjacencyList[currentVertex];
        while (current)
        {
            int adjVertex = current->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            current = current->next;
        }
    }

    free(queue->array);
    free(queue);
    free(visited);
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

    // deleteNode(graph, 2);
    // deleteEdge(graph, 1, 3);

    // printf("\nGraph after deletion:\n");
    // printGraph(graph);

    printf("\nBFS Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    free(graph->adjacencyList);
    free(graph);

    return 0;
}
