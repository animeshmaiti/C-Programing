#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb, end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
int quickShort(int arr[],int lb,int ub){
    int loc;
    if (lb<ub)
    {
        loc=partition(arr,lb,ub);
        quickShort(arr,lb,loc-1);
        quickShort(arr,loc+1,ub);
    }
}
int main()
{
    // printf("animesh maiti 2130006");
    int arr[9]={7,6,10,5,9,2,1,15,7};
    quickShort(arr,0,8);
    for (int i = 0; i <9; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}