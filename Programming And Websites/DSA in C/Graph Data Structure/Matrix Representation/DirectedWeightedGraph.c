#include <stdio.h>
#include <stdlib.h>

#define max 100
#define INF 9999

struct Graph
{
    int numVertices;
    int adjacencyMatrix[max][max];
    int weightMatrix[max][max];
};

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
            graph->weightMatrix[i][j] = INF;
        }
    }

    return graph;
}

void addWeightedEdge(struct Graph *graph, int src, int dest, int weight)
{
    graph->adjacencyMatrix[src][dest] = 1;
    graph->weightMatrix[src][dest] = weight;
}

void deleteNode(struct Graph *graph, int node)
{
    if (node < 0 || node >= graph->numVertices)
    {
        printf("Invalid node index\n");
        return;
    }
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->adjacencyMatrix[node][i] = 0;
        graph->adjacencyMatrix[i][node] = 0;
        graph->weightMatrix[node][i] = INF;
        graph->weightMatrix[i][node] = INF;
    }
}

void deleteEdge(struct Graph *graph, int src, int dest)
{
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices)
    {
        printf("Invalid edge indices\n");
        return;
    }
    graph->adjacencyMatrix[src][dest] = 0;
    graph->weightMatrix[src][dest] = INF;
}

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void BFS(struct Graph *graph, int startVertex)
{
    int visited[max] = {0};
    struct Queue *queue = createQueue(max);

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    free(queue->array);
    free(queue);
}

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isStackEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

void DFS(struct Graph *graph, int startVertex)
{
    int visited[max] = {0};
    struct Stack *stack = createStack(max);

    visited[startVertex] = 1;
    printf("%d ", startVertex);
    push(stack, startVertex);

    while (!isStackEmpty(stack))
    {
        int currentVertex = stack->array[stack->top];
        int found = 0;

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                push(stack, i);
                found = 1;
                break;
            }
        }

        if (!found)
            pop(stack);
    }

    free(stack->array);
    free(stack);
}

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

int main()
{
    struct Graph *graph = createGraph(5);

    addWeightedEdge(graph, 0, 1, 2);
    addWeightedEdge(graph, 0, 3, 1);
    addWeightedEdge(graph, 1, 2, 4);
    addWeightedEdge(graph, 1, 4, 5);
    addWeightedEdge(graph, 2, 3, 3);
    addWeightedEdge(graph, 3, 4, 7);

    printf("\nOriginal Graph:\n");
    displayGraph(graph);

    // deleteNode(graph, 2);

    // deleteEdge(graph, 1, 4);

    // printf("\nAfter Deletion:\n");
    // displayGraph(graph);

    printf("\nBFS Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    printf("\nDFS Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    free(graph);

    return 0;
}
