#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int d)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *buildTree(struct node *root)
{
    printf("Enter the data: ");
    int data;
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    root = createNode(data);

    printf("Enter data for inserting in left of %d\n", data);
    root->left = buildTree(root->left);
    printf("Enter data for inserting in right of %d\n", data);
    root->right = buildTree(root->right);

    return root;
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

void levelOrderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    struct node *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;
    queue[++rear] = NULL;

    while (front != rear)
    {
        struct node *temp = queue[++front];

        if (temp == NULL)
        {
            printf("\n");
            if (front != rear)
            {
                queue[++rear] = NULL;
            }
        }
        else
        {
            printf("%d ", temp->data);
            if (temp->left)
            {
                queue[++rear] = temp->left;
            }
            if (temp->right)
            {
                queue[++rear] = temp->right;
            }
        }
    }
}

void recursiveLevelOrderTraversal(struct node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        recursiveLevelOrderTraversal(root->left, level - 1);
        recursiveLevelOrderTraversal(root->right, level - 1);
    }
}

int getHeight(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

void levelOrder(struct node *root)
{
    int height = getHeight(root);
    for (int i = 1; i <= height; i++)
    {
        recursiveLevelOrderTraversal(root, i);
        printf("\n");
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{

    struct node *root = NULL;
    root = buildTree(root);
    printf("\nTree is:-\n");
    display(root, 0);

    printf("\nPreorder traversal is: ");
    preorder(root);

    printf("\nInorder traversal is: ");
    inorder(root);

    printf("\nPostorder traversal is: ");
    postorder(root);

    printf("\nLevel order traversal (using recursion) is:\n");
    levelOrder(root);

    printf("\nLevel order traversal (using queue) is:\n");
    levelOrderTraversal(root);

    return 0;
}
