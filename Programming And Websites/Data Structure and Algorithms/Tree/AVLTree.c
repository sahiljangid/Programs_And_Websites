#include <stdio.h>
#include <stdlib.h>

// Node structure with additional 'height' field
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

// Function to get the height of a node
int getHeight(struct node *root)
{
    if (root == NULL)
        return -1;
    return root->height;
}

// Function to update the height of a node
void updateHeight(struct node *root)
{
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    root->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to perform a right rotation
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t = x->right;

    // Perform rotation
    x->right = y;
    y->left = t;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    // Return new root
    return x;
}

// Function to perform a left rotation
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t = y->left;

    // Perform rotation
    y->left = x;
    x->right = t;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// Create a new node with given data
struct node *createNode(int d)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0; // Newly added node has height 1
    return newNode;
}

// Function to insert a node into AVL tree
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = insert(root->right, data);
    }

    // Update height of the current node
    updateHeight(root);

    // Get the balance factor
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data >= root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data >= root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to find the node with the minimum value in a tree
struct node *findMin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from AVL tree
struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    // Update height of the current node
    updateHeight(root);

    // Get the balance factor
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void search(struct node *root, int data)
{
    if (root == NULL)
    {
        printf("Number Not Found\n");
    }
    else if (data == root->data)
    {
        printf("Number founded\n");
    }
    else if (data < root->data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
}

void display(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    display(root->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->data);

    display(root->left, level + 1);
}

int main()
{
    struct node *root = NULL;
    int choice, data;

    do
    {
        printf("\n1. Insert a node\n2. Delete a node\n3. Search for data\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 4:
            printf("AVL Tree:-\n");
            display(root, 0);
            break;
        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
