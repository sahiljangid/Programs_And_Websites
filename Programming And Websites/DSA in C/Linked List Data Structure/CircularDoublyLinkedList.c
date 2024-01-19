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
        temp->next = temp;
        temp->prev = temp;
        temp->data = item;
        head = temp;
        printf("Node Inserted Successfully\n");
    }
    else
    {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
        temp->data = item;
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
    }
    else
    {
        int loc;
        printf("Enter Location: ");
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
        printf("Enter data: ");
        scanf("%d", &item);
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next->prev = temp;
        ptr->next = temp;
        temp->data = item;
        printf("Node Inserted Successfully\n");
    }
}

void InsertionAtEnd()
{
    int item;

    printf("Enter data: ");
    scanf("%d", &item);

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        temp->data = item;
        head = temp;
        printf("Node Inserted Successfully\n");
    }
    else
    {
        struct node *last;
        last = head->prev;
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
        temp->data = item;
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

    if (head->next == head)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        head = ptr->next;
        ptr->next = NULL;
        ptr->prev = NULL;
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
        printf("Enter location: ");
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
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;

        if (head == ptr)
        {
            head = ptr->next;
            if (head == ptr)
            {
                head = NULL;
                free(ptr);
                printf("Node Deleted Successfully\n");
                return;
            }
        }
        ptr->next = NULL;
        ptr->prev = NULL;
        free(ptr);
        printf("Node Deleted Successfully\n");
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

    if (head->next == head)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        struct node *last = head->prev;

        last->prev->next = head;
        head->prev = last->prev;
        last->next = NULL;
        last->prev = NULL;
        free(last);
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
        printf("Head[%d]-->", head);
        do
        {
            printf("[%d][%d][%d]", ptr->prev, ptr->data, ptr->next);
            if (ptr->next != head)
            {
                printf("--><--");
            }
            ptr = ptr->next;
        } while (ptr != head);
    }
    printf("\n");
}

int main()
{
    printf("*********************Doubly Linked List*********************\n");
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