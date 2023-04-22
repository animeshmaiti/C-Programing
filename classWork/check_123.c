#include <stdio.h>

int main(){
    int variable=23;
    switch (variable)
    {
    case 1://constant-expression 
        printf("this number is one\n");        
        break;
    case 2:
        printf("this number is two\n");        
        break;
    case 3:
        printf("this number is three\n");        
        break;
    default:
        printf("this number is not 1,2,3\n");
        break;
    }
    return 0;
}