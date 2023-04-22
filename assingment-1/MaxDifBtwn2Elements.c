#include <stdio.h>
int maxDiff(int arr[], int arr_size)
{
    int maxDiff = arr[1] - arr[0];
    int min = arr[0];
    int i;
    for (i = 1; i < arr_size; i++)
    {
        if (arr[i] - min > maxDiff)
            maxDiff = arr[i] - min;
        if (arr[i] < min)
            min = arr[i];
    }
    return maxDiff;
}

int main()
{
    printf("animesh maiti\n");
    int arr[] = {20, 13, 53, 84, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum difference is %d", maxDiff(arr, size));
    getchar();
    return 0;
}