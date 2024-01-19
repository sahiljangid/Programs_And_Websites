#include <stdio.h>
#include <stdlib.h>

#define max_size 5

int elements[max_size];
int priorities[max_size];
int size = 0;

int isFull()
{
    return (size == max_size);
}

int isEmpty()
{
    return (size == 0);
}

void enqueue()
{
    int data, priority;
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter priority: ");
    scanf("%d", &priority);
    int i = size - 1;

    while (i >= 0 && priorities[i] > priority)
    {
        elements[i + 1] = elements[i];
        priorities[i + 1] = priorities[i];
        i--;
    }
    elements[i + 1] = data;
    priorities[i + 1] = priority;
    size++;
    printf("%d element inserted successfully with %d priority\n", data, priority);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    int data = elements[0];
    int priority = priorities[0];
    for (int i = 0; i < size - 1; i++)
    {
        elements[i] = elements[i + 1];
        priorities[i] = priorities[i + 1];
    }
    size--;
    printf("%d element deleted successfully with %d priority\n", data, priority);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue is:\n");
    printf("Data   Priority\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d   :   %d\n", elements[i], priorities[i]);
    }
    printf("\n");
}

int main()
{

    printf("*************Priority Queue*************");
    while (1)
    {

        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice! Try Again");
            break;
        }
    }

    return 0;
}