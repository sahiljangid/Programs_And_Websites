#include <stdio.h>
#include <stdlib.h>

#define size 5

int queue[size];
int front = -1, rear = -1;

void enqueuerear()
{
    int data;

    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Queue is full");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (rear == size - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    queue[rear] = data;
}

void enqueuefront()
{
    int data;

    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("Queue is full");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = size - 1;
    }
    else
    {
        front--;
    }
    queue[front] = data;
}

void dequeuefront()
{
    int data;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
        return;
    }
    else if (front == rear)
    {
        data = queue[front];
        printf("%d element removed\n", data);
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        data = queue[front];
        printf("%d element removed\n", data);
        front = 0;
    }
    else
    {
        data = queue[front];
        printf("%d element removed\n", data);
        front++;
    }
}

void dequeuerear()
{
    int data;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
        return;
    }
    else if (front == rear)
    {
        data = queue[rear];
        printf("%d element removed\n", data);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        data = queue[rear];
        printf("%d element removed\n", data);
        rear = size - 1;
    }
    else
    {
        data = queue[rear];
        printf("%d element removed\n", data);
        rear--;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue is: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }
    printf("%d ", queue[rear]);
}

int main()
{

    printf("*************Double Ended Queue*************");
    while (1)
    {

        printf("\n1. EnqueueRear\n2. EnqueueFront\n3. DequeueFront\n4. DequeueRear\n5. Display\n6. Exit");
        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueuerear();
            break;
        case 2:
            enqueuefront();
            break;
        case 3:
            dequeuefront();
            break;
        case 4:
            dequeuerear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice! Try Again");
            break;
        }
    }

    return 0;
}