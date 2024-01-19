#include<stdio.h>


int main()
{
    int arr[] = {2,9,4,8,7,1,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array is: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    for(int i = 0; i < size; i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[min] < arr[j])
            {
                min = j;
            }
        }
        int temp;
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    printf("\nSorted Array is: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }



    return 0;
}