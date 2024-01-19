#include <stdio.h>

void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);

        quickSort(arr, left, pi - 1); // Left partition
        quickSort(arr, pi + 1, right); // Right partition
    }
}

int main()
{

    int arr[] = {12, 3, 1, 6, 23, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int left = 0;
    int right = size - 1;

    printf("\nArray is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    quickSort(arr, left, right);

    printf("\n\nSorted Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}