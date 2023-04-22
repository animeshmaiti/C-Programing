# include <stdio.h>
# include <stdlib.h>

int main()
{
    int a[5]={1, 2, 3, 4, 5}, i=0; //Static Array
    
    int *ptr1, *ptr2=NULL;
    //printf("\n %p %d %p", a, a[0], &a);
    //printf("\n%d", i++);
    //printf("\n%d", ++i);
    //ptr1=a+1;
    /*printf("\n %p %p %p", a, &a[1], ptr1); // a=(a+1)
    printf("\n %p %p %p", a, &a[2], ++ptr1);
    printf("\n %p %p %p", a, &a[3], ++ptr1);
    printf("\n %p %p %d", a, &a[4], *(++ptr1));
    
    printf("\n %p %p %d", a, &a[5], *(++ptr1));
    
    printf("\n %p %p %d", a, &a[6], (++ptr1));*/
    
    ptr2=(int*)malloc(5*sizeof(int));
    
    for(i=0;i<5;i++)
    {
            scanf("\n%d", ptr2);
            printf("\t%p", ptr2);
            printf("\t%d", *ptr2);
            ptr2++;
    }
    
    for(i=0;i<5;i++)
    {
            --ptr2;
            printf("\n%p",ptr2);
            printf("\t%d", *ptr2);
    }
    
    return 0;
}