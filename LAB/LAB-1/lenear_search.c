#include <stdio.h>

int Search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("element found");
            return i;
        }
    }
    printf("element not found");
}

int main()
{
    printf("Arnab pal 213099\n");
    int size = 9;
    int arr[] = {1, 8, 12, 98, 68, 9, 2, 74, 0};
    printf("original array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int element = 13,element2=98;
    printf("searching element is %d\n",element);
    Search(arr, size, element);
    printf("\n");
    printf("searching element is %d\n",element2);
    Search(arr, size, element2);
    return 0;
}