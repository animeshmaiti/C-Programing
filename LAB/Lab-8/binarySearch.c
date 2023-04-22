#include <stdio.h>
int binarySearch(int arr[], int n, int data)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (data == arr[mid])
        {
            printf("element found at %dth index", mid);
            return mid;
        }
        else if (data > arr[mid])
        {
            left = mid + 1;
        }
        else if (data < arr[mid])
        {
            right = mid - 1;
        }
    }
    printf("element is not in this array\n");
    return -1;
}
int main()
{
    printf("Aadiptya Basuli 2130095\n");
    int arr[]={1,7,9,11,12,14,16,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i <n; i++)
    {
        printf("%d ",arr[i]);
    }
    int data=16;
    printf("\nsearching element %d\n",data);
    binarySearch(arr,n,data);
    return 0;
}