#include <stdio.h>
void oddEven(int);

void oddEven(int a)
{
    if (a % 2 == 0)
    {
        printf("this is a even number\n");
    }
    else
    {
        printf("this is a odd number\n");
    }
}

int main()
{
    int a = 24;
    oddEven(a);
    return 0;
}