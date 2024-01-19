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

    int l = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    int r = size - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == data)
        {
            printf("\nElement is present in the array");
            // break;
            exit(0);
        }
        else if (data < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("\nElement is not present in the array");

    return 0;
}