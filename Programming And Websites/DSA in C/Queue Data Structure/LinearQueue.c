#include <stdio.h>
#include<stdlib.h>

#define size 5
int queue[size];
int front = -1, rear = -1;

void enqueue()
{
    int data;
    if (rear == size - 1)
    {
        printf("Queue is full");
        return;
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    queue[rear] = data;
}

void dequeue()
{
    int data;
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        data = queue[front];
        printf("%d element removed\n", data);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue is: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{

    printf("*************Linear Queue*************");
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