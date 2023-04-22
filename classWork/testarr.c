#include <stdio.h>

int main(){
    int arr[4],i;
    for (int i = 0; i < 4; i++)
    arr[i]=i;
 
    for (int i = 0; i < 4; i++)
    printf(" %d",arr[i]);
    printf("\n");
    for (int i = 0; i < 4;i++)
    printf(" %d",i[arr]);
    printf("\n");
    for (int i = 0; i < 4; i++)
    printf(" %d",*(arr+i));
    printf("\n");
    for (int i = 0; i < 4; i++)
    printf(" %d",*(i+arr));
    
    

    return 0;
}