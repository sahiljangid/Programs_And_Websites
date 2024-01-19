#include <stdio.h>

int main()
{
    int arr[] = {4, 8, 2, 6, 0, 1, 5};

    printf("Array is: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    // Insertion Sorting

    for (int i = 1; i < 7; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted Array is: ");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}