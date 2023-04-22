#include <stdio.h>
#include <stdlib.h>

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) // condition for swaping
            {
                // swap element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    printf("Arnab pal 213099\n");
    int *arr;
    int n;
    printf("enter the number of element\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d \n", arr[i]);

    printf("largest number is %d\n", arr[0]);
    printf("smallest number is %d", arr[n - 1]);
    return 0;
}
