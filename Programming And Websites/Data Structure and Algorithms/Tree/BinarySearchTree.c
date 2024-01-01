#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int value)
{
    // Allocate memory for a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct node *insert(struct node *root, int value)
{
    // If the tree is empty, create a new node
    if (root == NULL)
    {
        return createNode(value);
    }

    // Recursive insertion based on the value
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search for a value in the BST
struct node *search(struct node *root, int value)
{
    // If the value is not found or the tree is empty
    if (root == NULL || root->data == value)
    {
        return root;
    }

    // Recursive search based on the value
    if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

// Function to find the node with the minimum value in a BST
struct node *findMin(struct node *root)
{
    // Traverse left until the leftmost node is found
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the BST
struct node *deleteNode(struct node *root, int value)
{
    // If the tree is empty, return
    if (root == NULL)
    {
        return root;
    }

    // Recursive deletion based on the value
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
        // Node with only one child or no child
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

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct node *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


// Function to display the tree structure
void displayTree(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    // Display the right subtree
    displayTree(root->right, level + 1);

    // Indent based on the level and print the data
    for (int i = 0; i < level * 4; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Display the left subtree
    displayTree(root->left, level + 1);
}

// Main function
int main()
{
    // Declare the root of the BST
    struct node *root = NULL;
    int choice, value;

    // Menu-driven loop for user interaction
    do
    {
        // Display menu options
        printf("\n1. Insert a node\n2. Delete a node\n3. Search for data\n4. Inorder traversal\n5. Display tree\n6. Quit\n");
        printf("Enter your choice: ");
        // Accept user choice
        scanf("%d", &choice);

        // Switch based on the user's choice
        switch (choice)
        {
        case 1:
            // Insert a value into the BST
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            // Delete a value from the BST
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 3:
            // Search for a value in the BST
            printf("Enter the value to search: ");
            scanf("%d", &value);
            if (search(root, value) != NULL)
            {
                printf("Value %d is present in the BST.\n", value);
            }
            else
            {
                printf("Value %d is not found in the BST.\n", value);
            }
            break;

        case 4:
            // Perform inorder traversal of the BST
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            // Display the tree structure
            printf("BST Structure:\n");
            displayTree(root, 0);
            break;

        case 6:
            // Exit the program
            break;

        default:
            // Invalid choice
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);
    return 0;
}
