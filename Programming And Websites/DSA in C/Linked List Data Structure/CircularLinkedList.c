
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
        return;
    }

    int item;
    printf("Enter data: ");
    scanf("%d", &item);

    if (head == NULL)
    {
        head = temp;
        temp->data = item;
        temp->next = head;
        printf("Node Inserted Successfully\n");
    }

    else
    {
        struct node *ptr;
        ptr = head;

        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        temp->data = item;
        ptr->next = temp;
        temp->next = head;
        head = temp;
        printf("Node Inserted Successfully\n");
    }
}

void InsertionAtSpecificLocation()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    int item, loc;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Can't Insert\n");
    }
    else
    {
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
        ptr->next = temp;
        temp->data = item;
        printf("Node Inserted Successfully\n");
    }
}

void InsertionAtEnd()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Overflow\n");
        return;
    }
    int item;
    printf("Enter data: ");
    scanf("%d", &item);
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
        temp->data = item;
        printf("Node Inserted Successfully\n");
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
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
    }
    else if (head->next == head)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        struct node *first;
        first = head;
        ptr->next = first->next;
        head = first->next;
        first->next = NULL;
        free(first);
        printf("Node Deleted Successfully\n");
    }
}

void DeletionAtSpecificLocation()
{
    struct node *ptr;
    int loc;
    ptr = head;
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Enter Location: ");
    scanf("%d", &loc);

    if (loc == ptr->data && ptr->next == head)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        while (ptr->next->data != loc)
        {
            if (ptr->next == head)
            {
                printf("Location not found\n");
                return;
            }
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
            printf("Node Deleted Successfully\n");
        }
        else
        {
            struct node *tempadd;
            tempadd = ptr->next->next;
            ptr->next->next = NULL;
            ptr->next = tempadd;
            printf("Node Deleted Successfully\n");
        }
    }
}

void DeletionAtEnd()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        printf("Node Deleted Successfully\n");
    }
    else
    {
        struct node *ptr, *ptrprev;
        ptr = head;
        while (ptr->next != head)
        {
            ptrprev = ptr;
            ptr = ptr->next;
        }
        ptrprev->next = ptr->next;
        ptr->next = NULL;
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
