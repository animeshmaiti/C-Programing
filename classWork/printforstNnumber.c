#include <stdio.h>

int main(){
    int n,i=1;
    printf("enter the value n\n");
    scanf("%d",&n);
    for (int j = 1; j <= n; j++)
    {
        printf("%d\n",j);
    }
    
    while (i<=n)
    {
        printf("%d\n",i);
        i++;
    }
    
    
    return 0;
}