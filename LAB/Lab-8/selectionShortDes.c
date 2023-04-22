#include <stdio.h>
void swap(int *element, int *element2)
{
	int temp = *element;
	*element = *element2;
	*element2 = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, minIdx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        minIdx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[minIdx])
            minIdx = j;
 
        // Swap the found minimum element with the first element
           if(minIdx != i)
            swap(&arr[minIdx], &arr[i]);
    }
}


int main(){
    // printf("animesh maiti 2130006");
    printf("Aadiptya Basuli 2130095\n");    
    int arr[7]={9,35,8,94,5,48,44};
    printf("unsorted array is\n");
    for (int i = 0; i <7; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nsorted array is \n");
    selectionSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}