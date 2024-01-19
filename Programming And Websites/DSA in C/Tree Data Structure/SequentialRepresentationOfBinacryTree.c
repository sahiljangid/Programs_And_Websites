#include <stdio.h>
#include <stdlib.h>

#define size 10

struct node
{
    int data;
};

struct node *createNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    return newnode;
}

void insertNode(struct node *tree[], int data, int index)
{
    if (index < size)
    {
        tree[index] = createNode(data);
    }
    else
    {
        printf("Index out of bounds\n");
    }
}

void inorderTraversal(struct node *tree[], int index)
{
    if (index < size && tree[index] != NULL)
    {
        inorderTraversal(tree, 2 * index + 1);
        printf("%d ", tree[index]->data);
        inorderTraversal(tree, 2 * index + 2);
    }
}

int main()
{

    printf("******Binary Tree Sequential Representation******\n");
    struct node *tree[size] = {NULL};

    insertNode(tree, 1, 0);
    insertNode(tree, 2, 1);
    insertNode(tree, 3, 2);
    insertNode(tree, 4, 3);
    insertNode(tree, 5, 4);

    printf("Inorder Traversal: ");
    inorderTraversal(tree, 0);
    return 0;
}