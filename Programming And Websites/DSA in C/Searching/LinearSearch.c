#include <stdio.h>

int main()
{
    int arr[5];

    printf("Enter 5 elements one by one: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array is: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEneter an element for search in the array: ");
    int data;
    scanf("%d", &data);

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == data)
        {
            printf("\nElement is present in the array");
            // break;
            exit(0);
        }
    }
    printf("\nElement is not present in the array");

    return 0;
}