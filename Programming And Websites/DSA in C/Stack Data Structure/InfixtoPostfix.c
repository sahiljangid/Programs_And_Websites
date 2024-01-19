#include <stdio.h>
#define size 50

char stk[size];

int top = -1;

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(char c)
{
    stk[++top] = c;
}

char pop()
{
    char c = stk[top];
    top--;
    return c;
}

int precedence(char ch)
{
    if (isempty())
    {
        return -1;
    }

    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }

    return -1;
}

void infixtopostfix(char *infix, char *postfix)
{
    int j = 0;
    for (int i = 0; i < infix[i] != '\0'; i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == ' ')
        {
            continue;
        }
        else if (infix[i] == '(')
        {
            stk[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top > -1 && stk[top] != '(')
                postfix[j++] = stk[top--];
            top--;
        }
        else
        {
            while (!isempty() && precedence(stk[top]) >= precedence(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
    }
    while (!isempty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[size];
    char postfix[size];
    printf("Enter an Infix expression: ");
    gets(infix);
    infixtopostfix(infix, postfix);
    printf("Infix: %s", infix);
    printf("\nPostfix: %s", postfix);

    return 0;
}