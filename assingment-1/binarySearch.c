// WARP using recursion to search an element in a dynamic array of n integers using binary search.
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // condition for swaping
            {
                // swap element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int low, int high, int element)
{
    int mid;
    if (high >= low)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            return mid + 1;
        }
        else if (arr[mid] < element)
        {
            return binarySearch(arr, mid + 1, high, element);
        }
        else
        {
            return binarySearch(arr, low, mid - 1, element);
        }
    }
    return -1;
}
int main()
{
    printf("animesh maiti 2130006\n");
    int *arr, n = 5, element,res;
    arr = (int *)malloc(n * sizeof(int));
    printf("enter 5 elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }
    printf("enter the searching element\n");
    scanf("%d", &element);
    bubbleSort(arr,n);
    res= binarySearch(arr,0,n-1,element);
    if (res==-1)
    {
        printf("element is not found\n");
    }
    else
    {
        printf("element found at index %d\n",res);
    }
    

    return 0;
}