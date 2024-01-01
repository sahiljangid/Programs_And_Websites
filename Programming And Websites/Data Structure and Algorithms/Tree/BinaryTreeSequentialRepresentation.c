#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent a node in the binary tree
struct Node
{
    int data;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    return newNode;
}

// Function to insert a new node in the binary tree
void insertNode(struct Node *tree[], int data, int index)
{
    if (index < MAX_SIZE)
    {
        tree[index] = createNode(data);
    }
    else
    {
        printf("Array index out of bounds\n");
    }
}

// Function to print the binary tree in inorder traversal
void inorderTraversal(struct Node *tree[], int index)
{
    if (index < MAX_SIZE && tree[index] != NULL)
    {
        inorderTraversal(tree, 2 * index + 1);
        printf("%d ", tree[index]->data);
        inorderTraversal(tree, 2 * index + 2);
    }
}

int main()
{
    printf("********Binary Tree Sequential Representation********\n");
    struct Node *tree[MAX_SIZE] = {NULL}; // Initialize the array of pointers to nodes

    // Insert nodes into the binary tree
    insertNode(tree, 1, 0);
    insertNode(tree, 2, 1);
    insertNode(tree, 3, 2);
    insertNode(tree, 4, 3);
    insertNode(tree, 5, 4);
    insertNode(tree, 6, 5);
    insertNode(tree, 7, 6);

    // Print the binary tree in inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(tree, 0);
    printf("\n");

    return 0;
}
