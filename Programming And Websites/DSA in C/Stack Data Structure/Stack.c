#include <stdio.h>

#define size 5
int stk[size];
int top = -1;

void push(int data)
{
    if (top == size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stk[top] = data;
    printf("%d Element inserted successfully\n", data);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    int data = stk[top];
    top--;
    printf("%d Element deleted successfully\n", data);
}

void full()
{
    if (top == size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    printf("Stack is not full\n");
}

void empty()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

void print()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stk[i]);
    }
    printf("\n");
}

int main()
{
    printf("***************Wel-Come***************");
    printf("\nLet's play with stack data structure\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        int choice, data;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid Input! Try again!");
            break;
        }
    }
    return 0;
}