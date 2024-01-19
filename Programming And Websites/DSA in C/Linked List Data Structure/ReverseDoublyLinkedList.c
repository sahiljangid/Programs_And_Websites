#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;

void InsertionAtBegining()
{
    int item;

    printf("Enter data: ");
    scanf("%d", &item);

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = item;
        head = temp;
        printf("Node Inserted Successfully\n");
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        temp->data = item;
        temp->prev = NULL;
        printf("Node Inserted Successfully\n");
    }
}

void InsertionAtSpecificLocation()
{
    int item;
    struct node *ptr;
    ptr = head;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("List is Empty, Can't Insert\n");
        return;
    }
    else
    {
        int loc;

        printf("Enter Location: ");
        scanf("%d", &loc);
        printf("Enter data: ");
        scanf("%d", &item);
        while (ptr->data != loc)
        {
            if (ptr->next == NULL)
            {
                printf("Location not found\n");
                return;
            }
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            temp->next = NULL;
            temp->data = item;
            ptr->next = temp;
            temp->prev = ptr;
            printf("Node Inserted Successfully\n");
        }
        else
        {
            temp->next = ptr->next;
            ptr->next->prev = temp;
            ptr->next = temp;
            temp->prev = ptr;
            temp->data = item;
            printf("Node Inserted Successfully\n");
        }
    }
}

void InsertionAtEnd()
{
    int item;

    printf("Enter data: ");
    scanf("%d", &item);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        temp->next = NULL;
        temp->data = item;
        temp->prev = NULL;
        head = temp;
        printf("Node Inserted Successfully\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->next = NULL;
        temp->data = item;
        temp->prev = ptr;
        ptr->next = temp;
        printf("Node Inserted Successfully\n");
    }
}

void DeletionAtBegining()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (ptr->next == NULL)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        ptr->next->prev = NULL;
        head = ptr->next;
        ptr->next = NULL;
        free(ptr);
        printf("Node Deleted Successfully\n");
    }
}

void DeletionAtSpecificLocation()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int loc;
        printf("Enter Location: ");
        scanf("%d", &loc);

        while (ptr->data != loc)
        {
            if (ptr->next == NULL)
            {
                printf("Location not found\n");
                return;
            }
            ptr = ptr->next;
        }
        if (head->next == NULL)
        {
            head = NULL;
            printf("Node Deleted Successfully\n");
        }
        else if (ptr->next == NULL)
        {
            ptr->prev->next = NULL;
            ptr->prev = NULL;
            free(ptr);
            printf("Node Deleted Successfully\n");
        }
        else if (ptr->prev == NULL)
        {
            ptr->next->prev = NULL;
            head = ptr->next;
            ptr->next = NULL;
            free(ptr);
            printf("Node Deleted Successfully\n");
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->next = NULL;
            ptr->prev = NULL;
            free(ptr);
            printf("Node Deleted Successfully\n");
        }
    }
}

void DeletionAtEnd()
{
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (ptr->next == NULL)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next->prev = NULL;
        ptr->next = NULL;
        printf("Node Deleted Successfully\n");
    }
}

void reverseLinkedList()
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    ptr1 = NULL;
    printf("Linked List Reversed\n");
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
        printf("Head[%d]-->", head);
        while (ptr != NULL)
        {
            printf("[%d][%d][%d]", ptr->prev, ptr->data, ptr->next);
            if (ptr->next != NULL)
            {
                printf("--><--");
            }
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int main()
{
    printf("*********************Doubly Linked List*********************\n");
    int choice;
    do
    {
        printf("1. Insertion At Begining\n2. Insertion At End\n3. Insertion At Specific Location\n4. Deletion At Begining\n5. Deletion At End\n6. Deletion At Specific Location\n7. Display Linked List\n8. Reverse Linked List\n9. Exit\n");
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
        case 8:
            reverseLinkedList();
            break;
        default:
            break;
        }

    } while (choice != 9);
}
