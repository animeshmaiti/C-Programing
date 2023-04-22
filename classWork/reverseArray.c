#include <stdio.h>

void reverse(char arr[],int start,int end){
    while (start<end)
    {
        char temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;   
    }
    

}

int main(){
    printf("animesh maiti 2130006");
    char arr[]={'s','t','o','p'};
    
    return 0;
}