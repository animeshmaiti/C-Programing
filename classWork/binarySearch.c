#include <stdio.h>
#include <math.h>

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int[], int);
void sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (size_t i = 0; i < n; i++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
            SWAP(list[i], list[min], temp);
        }
    }
}
void main(void)
{
    int i, n;
    int list[MAX_SIZE];
    printf("enter the genarate number size\n");
    scanf("%d", &n);
    if (n < 1 || n > MAX_SIZE)
    {
        fprintf(stderr, "improper value of n\n");
        // exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++)
    {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }
    sort(list, n);
    printf("\n sorted array: \n ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
        printf("\n");
    }
}