#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int selectionSort(int arr[], int n)
{
    int i, j, minIdx;

    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(&arr[minIdx], &arr[i]);
    }
}

int main()
{
    printf("Arnab pal 213099\n");
    int *arr;
    int n;
    printf("enter the number of element\n");
    scanf("%d", &n);
    //dynamicaly allocated
    arr = (int *)malloc(n * sizeof(int));
    //taking elements
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    //printing array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    printf("smallest number adress location is %p\n", &arr[0]);
    printf("largest number adress location is %p\n", &arr[n - 1]);
    printf("smallest number is %d\n", arr[0]);
    printf("largest number is %d", arr[n - 1]);

    return 0;
}
