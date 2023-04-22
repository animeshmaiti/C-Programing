#include <stdio.h>
int merge(int *arr, int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[ub + 1];
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++, k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            j++, k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++, k++;
        }
    }
    for (int i = lb; i <= ub; i++)
    {
        arr[i] = b[i];
    }
}
int mergeShort(int *arr, int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeShort(arr, lb, mid);
        mergeShort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    // printf("animesh maiti 2130006\n");
    int arr[9]={15,5,24,8,1,3,16,10,20};
    mergeShort(arr,0,8);
    for (int i = 0; i <9; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}