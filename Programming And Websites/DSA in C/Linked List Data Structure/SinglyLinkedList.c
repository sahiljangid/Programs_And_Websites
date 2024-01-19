#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void InsertionAtBegining()
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        int item;
        printf("Enter data: ");
        scanf("%d", &item);
        temp->data = item;
        temp->next = head;
        head = temp;
        printf("Node Inserted Successfully\n");
    }
}

void InsertionAtSpecificLocation()
{
    struct node *temp, *ptr;
    int item, loc;
    printf("Enter location : ");
    scanf("%d", &loc);
    printf("Enter data : ");
    scanf("%d", &item);

    temp = (struct node *)malloc(sizeof(struct node));

    ptr = head;
    if (temp == NULL)
    {
        printf("Overflow\n");
    }
    else if (ptr == NULL)
    {
        printf("Can't Insert\n");
    }
    else
    {
        while (ptr->data != loc)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Location not found\n");
                return;
            }
        }
        if (ptr->next == NULL)
        {
            temp->data = item;
            ptr->next = temp;
            temp->next = NULL;
            printf("Node Inserted Successfully\n");
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
            temp->data = item;
            printf("Node Inserted Successfully\n");
        }
    }
}

void InsertionAtEnd()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    int item;
    printf("Enter data: ");
    scanf("%d", &item);
    if (temp == NULL)
    {
        printf("Overflow\n");
    }
    else if (head == NULL)
    {
        head = temp;
        temp->data = item;
        temp->next = NULL;
        printf("Node Inserted Successfully\n");
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->data = item;
        temp->next = NULL;
        printf("Node Inserted Successfully\n");
    }
}

void DeletionAtBegining()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Node Deleted Successfully\n");
    }
}

void DeletionAtSpecificLocation()
{
    struct node *ptr;
    int loc;

    ptr = head;
    if (ptr == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Enter location: ");
    scanf("%d", &loc);
    if (ptr->data == loc)
    {
        head = ptr->next;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        while (ptr->next->data != loc)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
            {
                printf("Location not found\n");
                return;
            }
        }
        ptr->next = ptr->next->next;
        printf("Node Deleted Successfully\n");
    }
}

void DeletionAtEnd()
{
    struct node *ptr, *ptrprev;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (ptr->next == NULL)
    {
        head = NULL;
        free(ptr);
        printf("Node Deleted Successfully\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptrprev = ptr;
            ptr = ptr->next;
        }
        ptrprev->next = NULL;
        free(ptr);
        printf("Node Deleted Successfully\n");
    }
}

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
        printf("Head--->");
        while (ptr != NULL)
        {
            printf("[%d][%d]", ptr->data, ptr->next);
            if (ptr->next != NULL)
            {
                printf("--->");
            }
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}

int main()
{
    printf("*********************Singly Linked List*********************\n");
    int choice;
    do
    {
        printf("1. Insertion At Begining\n2. Insertion At End\n3. Insertion At Specific Location\n4. Deletion At Begining\n5. Deletion At End\n6. Deletion At Specific Location\n7. Display Linked List\n8. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertionAtBegining();
            break;
        case 2:
            InsertionAtEnd();
            break;
        case 3:
            InsertionAtSpecificLocation();
            break;
        case 4:
            DeletionAtBegining();
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
}
