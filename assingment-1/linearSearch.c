// WARP (Write a Recursive Program) to search an element in a dynamic array of n integers using linear search.
#include <stdio.h>
#include <stdlib.h>
int searchElement(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("element found at indx %d",i);
            return i;
        }
    }
    printf("element not found");
}

int main()
{
    int *arr, n=5,element;
    printf("animesh maiti 2130006\n");
    arr = (int *)malloc(n * sizeof(int));
    printf("enter 5 elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d",&arr[i]);
    }
    printf("enter the searching element\n");
    scanf("%d",&element);
    searchElement(arr,n,element);

    
    return 0;
}