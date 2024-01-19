#include <stdio.h>

void bubbleAsort(int arr[], int size)
{
    // Bubble sort (Ascending sort)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleDsort(int arr[], int size)
{
    // Bubble sort (Descending sort)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements one by one into the array: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting Array Elements is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nWhich type of sorting you want to perform into your array, choose any one operation: ");
    printf("\n1. Ascending Sorting\n2. Descending Sorting\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        bubbleAsort(arr, size);
        break;
    case 2:
        bubbleDsort(arr, size);
        break;

    default:
        printf("Enter valid choice!");
        break;
    }

    printf("\nYour Sorted Array Elements is: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}