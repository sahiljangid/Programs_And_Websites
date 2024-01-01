#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

// Insert node at the begnning of the circular linked list
void InsertionAtBeginning()
{
    int item;
    printf("Enter data : ");
    scanf("%d", &item);
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        head = temp;
        temp->data = item;
        temp->next = head;
        // printf("%d\n",head->next);
        printf("Node Inserted!\n\n");
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        temp->data = item;
        ptr->next = temp;
        temp->next = head;
        head = temp;
        printf("Node Inserted!\n\n");
    }
}

// Insert Node at the end of the circular linked list
void InsertionAtEnd()
{
    int item;
    printf("Enter data : ");
    scanf("%d", &item);
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        head = temp;
        temp->data = item;
        temp->next = head;
        printf("Node Inserted!\n\n");
    }
    else
    {
        while (ptr->next != head)
        {
            /* code */
            ptr = ptr->next;
        }
        temp->data = item;
        ptr->next = temp;
        temp->next = head;

        printf("Node Inserted!\n\n");
    }
}

// Insert an node at specific location in circular linked list
void InsertionAtSpecificLocation()
{
    struct node *temp, *ptr;
    int item, loc;

    temp = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    if (ptr == NULL)
    {
        printf("Can't Insert\n\n");
    }
    else
    {
        printf("Enter Location : ");
        scanf("%d", &loc);

        while (ptr->data != loc)
        {
            if (ptr->next == head)
            {
                printf("Location not found\n");
                return;
            }
            ptr = ptr->next;
        }

        printf("Enter data : ");
        scanf("%d", &item);

        temp->next = ptr->next;
        ptr->next = temp;
        temp->data = item;
        printf("Node Inserted Successfully!\n\n");
    }
}

// Delete an node at begnning of the circular linked list
void DeletionAtBegnning()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty!\n\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (ptr->next != head)
        {
            /* code */
            ptr = ptr->next;
        }
        struct node *first;
        first = ptr->next;
        ptr->next = first->next;
        head = first->next;
        first->next = NULL;
        free(first);
        printf("Node Deleted Successfully\n\n");
    }
}

// Delete the node at the end of the circular linked list
void DeletionAtEnd()
{
    struct node *ptr, *ptrprev;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty!\n\n");
    }
    else if (ptr->next == head)
    {
        head = NULL;
        printf("Node Deleted Successfully\n\n");
    }
    else
    {
        while (ptr->next != head)
        {
            /* code */
            ptrprev = ptr;
            ptr = ptr->next;
        }
        ptrprev->next = ptr->next;
        ptr->next = NULL;
        free(ptr);
        printf("Node Deleted Successfully\n\n");
    }
}

// Delete node at specific location in circular linked list

void DeletionAtSpecificLocation()
{
    struct node *ptr;
    int loc;
    ptr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter Location : ");
    scanf("%d", &loc);
    if (loc == ptr->data && ptr->next == head)
    {
        free(head);
        head = NULL;
        printf("Node Deleted Successfully\n\n");
        return;
    }
    else
    {
        struct node *prevptr;
        while (ptr->next->data != loc)
        {
            if (ptr->next == head)
            {
                printf("Location not found\n");
                return;
            }
            prevptr = ptr;
            ptr = ptr->next;
        }

        if (loc == head->data)
        {
            struct node *ptr2;

            ptr2 = head;
            head = ptr2->next;
            ptr->next = ptr2->next;
            ptr2->next = NULL;
            free(ptr2);
            printf("Node Deleted Successfully\n\n");
        }
        else
        {
            struct node *tempadd;
            tempadd = ptr->next->next;
            ptr->next->next = NULL;
            ptr->next = tempadd;
            printf("Node Deleted Successfully\n\n");
        }
    }
}

// Dispaly Circular linked list

void display()
{
    struct node *ptr;
    ptr = head;

    if (ptr == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("Head[%d]--->", head);

        while (ptr->next != head)
        {
            printf("[%d][%d]", ptr->data, ptr->next);
            if (ptr->next != head)
            {
                printf("--->");
            }
            ptr = ptr->next;
        }
        printf("[%d][%d]", ptr->data, ptr->next);
        printf("--->Head[%d]", ptr->next);
        printf("\n\n");
    }
}


int main()
{
    int choice;
    printf("********************* WEL-COME *********************\n");

    do
    {
        printf("-->1.Insertion At Begnning\n-->2.Insertion At End\n-->3.Insertion At Specific Location\n-->4.Deletion At Begning\n-->5.Deletion At End\n-->6.Deletion At Specific Location\n-->7.Display Nodes\n-->8.Exit!\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertionAtBeginning();
            break;

        case 2:
            InsertionAtEnd();
            break;

        case 3:
            InsertionAtSpecificLocation();
            break;

        case 4:
            DeletionAtBegnning();
            break;

        case 5:
            DeletionAtEnd();
            break;

        case 6:
            DeletionAtSpecificLocation();
            break;

        case 7:
            display();
            break;

        default:
            break;
        }
    } while (choice != 8);

    return 0;
}