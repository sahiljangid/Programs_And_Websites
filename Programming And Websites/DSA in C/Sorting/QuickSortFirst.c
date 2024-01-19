#include <stdio.h>
void quickSort(int arr[], int left, int right)
{
    int i, j, pivot, temp;
    if (left < right)
    {
        pivot = left;
        i = left;
        j = right;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < right)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr, left, j - 1); // Left Partition
        quickSort(arr, j + 1, right); // Right partition
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