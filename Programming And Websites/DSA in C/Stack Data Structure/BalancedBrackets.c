#include <stdio.h>
#include <string.h>

#define size 50

char stk[size];
int top = -1;

int isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(char data)
{
    // if (isFull())
    // {
    //     printf("Stack is full");
    //     return;
    // }
    top++;
    stk[top] = data;
}

char pop()
{
    if (isEmpty())
    {
        return 1;
    }
    char data = stk[top];
    top--;
    return data;
}

int match_char(char temp, char s)
{
    if (temp == '{' && s == '}')
    {
        return 1;
    }
    if (temp == '[' && s == ']')
    {
        return 1;
    }
    if (temp == '(' && s == ')')
    {
        return 1;
    }
    return 0;
}

int checkbalance(char *str)
{
    char temp;
    for (int i = 0; i < strlen(str); i++) // Traverse
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            push(str[i]);
        }
        if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if (isEmpty())
            {
                return 0; // Invalid expression
            }
            else
            {
                temp = pop();
                if (!match_char(temp, str[i]))
                {
                    return 0; // Invalid expression
                }
            }
        }
    }
    if (isEmpty)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char expr[size];
    printf("Enter an string: ");
    gets(expr);

    int check = checkbalance(expr);
    if (check)
    {
        printf("Valid Expression");
    }
    else
    {
        printf("Invalid Expression");
    }

    return 0;
}