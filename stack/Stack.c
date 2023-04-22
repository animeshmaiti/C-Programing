#include <stdio.h>
#define s_size = 4
int top = -1;
int stack[];
void push()
{
    printf("enter the value\n");
    int val;
    scanf("%d", &val);
    top++;
    stack[top] = val;
}
void pop()
{
    printf("%d\n", stack[top]);
    top--;
}
void show(){
    for (int i = top; i >-1 ; i--)
    {
        printf("values are %d\n",stack[i]);
    }
    
}
int main()
{
    // printf("animesh maiti 2130006\n");
    push();
    push();
    push();
    pop();
    show();

    return 0;
}