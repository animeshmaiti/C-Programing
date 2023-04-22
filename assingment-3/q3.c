#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first = 1, diff=5, terms, value, sum = 0, i;

    printf("Enter the number of terms in AP series\n");
    scanf("%d", &terms);

    value = first;
    printf("AP SERIES\n");
    printf("%d ", value);
    value=first+diff;
    for (i = 0; i < terms; i++)
    {
        printf("%d ", value);
        sum = sum + value;
        diff=diff+6;
        value = value + diff;
    }

    return 0;
}