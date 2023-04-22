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
void show()
{
    for (int i = top; i > -1; i--)
    {
        printf("values are %d\n", stack[i]);
    }
}
int isempty()
{
    if (top == -1)
    {
        printf("it's empty\n");
    }
    else
    {
        printf("it's not empty\n");
    }
}
int main()
{
    int ch,n;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        push();
    }

    printf("n1.Check if the stack is empty\n");
    printf("n2.Display the contents of the stack\n");
    printf("n3.push\n");
    printf("n4.pop\n");
    while (1)
    {
        printf("enter the menue number\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("n1.Check if the stack is empty\n");
            isempty();
            break;
        case 2:
            printf("n2.Display the contents of the stack\n");
            show();
            break;
        case 3:
            printf("n3.push\n");
            push();
            break;
        case 4:
            printf("n4.pop\n");
            pop();
            break;

        default:
            printf("wrong choce\n");
            break;
        }
    }
    return 0;
}