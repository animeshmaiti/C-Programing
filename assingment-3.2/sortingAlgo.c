// Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort, Heap Sort.
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int lb, int ub)
{
    int first = arr[lb];
    int start = lb, end = ub;
    while (start < end)
    {
        while (arr[start] <= first)
        {
            start++;
        }
        while (arr[end] > first)
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
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int merge(int arr[], int lb, int mid, int ub)
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

int quickShort(int arr[],int lb,int ub){
    int loc;
    if (lb<ub)
    {
        loc=partition(arr,lb,ub);
        quickShort(arr,lb,loc-1);
        quickShort(arr,loc+1,ub);
    }
}
int mergeShort(int arr[], int lb, int ub)
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
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // condition for swaping
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
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
void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}
 
// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    printf("animesh maiti 2130006");

    return 0;
}