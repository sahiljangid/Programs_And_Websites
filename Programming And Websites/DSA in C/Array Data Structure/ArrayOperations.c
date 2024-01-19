#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    // Takes array input from the user
    printf("Enter %d Elements one by one: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Print the array elements
    printf("Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    // // Search Operation
    // // Index
    // printf("\nEnter the indexing : ");
    // int ind;
    // scanf("%d", &ind);
    // printf("The data is %d present at the index %d", arr[ind], ind);
    // // Data
    // printf("\nEnter the data from the array and get the index no. : ");
    // int d;
    // scanf("%d", &d);
    // for(int i = 0; i < size; i++)
    // {
    //     if(d == arr[i])
    //     {
    //         printf("The index no of the data %d is %d \n",d, i);
    //     }
    // }

    // Update
    // Index
    // printf("\nEnter the index for update the data: ");
    // int ind;
    // scanf("%d", &ind);
    // printf("Enter the data: ");
    // int d;
    // scanf("%d", &d);
    // arr[ind] = d;
    // printf("Updated Array is: ");
    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // Data
    // printf("\nEnter the data from the array which you wnat to update : ");
    // int olddata;
    // scanf("%d", &olddata);
    // printf("Enter the data : ");
    // int newdata;
    // scanf("%d", &newdata);
    // for(int i = 0; i < size; i++)
    // {
    //     if(olddata == arr[i])
    //     {
    //         arr[i] = newdata;
    //         break;
    //     }
    // }
    // printf("Updated Array is: ");
    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // Insertion
    // Index
    // printf("\nEnter the index:");
    // int ind;
    // scanf("%d", &ind);
    // printf("Enter the data: ");
    // int d;
    // scanf("%d", &d);
    // size += 1;
    // int k;
    // for(int i = size; i >= ind; i--)
    // {
    //     arr[i] = arr[i-1];
    //     k = i;
    // }
    // arr[k] = d;
    // printf("Updated Array is: ");
    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // Data
    // printf("\nEnter the data from the array:");
    // int olddata;
    // scanf("%d", &olddata);
    // printf("Enter the new data: ");
    // int d;
    // scanf("%d", &d);
    // int k;
    // int j;
    // for(int i = 0; i < size; i++)
    // {
    //     if(olddata == arr[i])
    //     {
    //         j = i;
    //         break;
    //     }
    // }
    // size += 1;
    // for(int i = size; i >= j; i--)
    // {
    //     arr[i] = arr[i-1];
    //     k = i;
    // }
    // arr[k] = d;
    // printf("Updated Array is: ");
    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // Delete
    // Index
    // printf("\nEnter the index for delete the element in the array: ");
    // int ind;
    // scanf("%d", &ind);
    // for(int i = ind; i <= size; i++)
    // {
    //     arr[i] = arr[i+1];
    // }
    // size -= 1;
    // printf("Updated Array is: ");
    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // Data
    printf("\nEnter the data from array for delete: ");
    int d;
    int j;
    scanf("%d", &d);
    for (int i = 0; i <= size; i++)
    {
        if (d == arr[i])
        {
            j = i;
        }
    }
    for (int i = j; i <= size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size -= 1;
    printf("Updated Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}