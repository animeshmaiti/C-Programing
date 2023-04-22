#include <stdio.h>
float factorial(int n)  
{  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}  

int main(){
    // printf("animesh maiti 2130006");
    float add=0,fact;
    for (float i = 1; i <= 7; i++)
    {
        fact=factorial(i);
        add=add+(i/fact);
    }
    printf("first 7 add is %f",add);
    
    return 0;
}