
#include <stdio.h>
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

void insertion(int pos)
{
    int x;
    printf("enter the element\n");
    scanf("%d", &x);
    top++;
    for (int i = top; i >= pos; i--)
    {
        stack[i] = stack[i - 1];
    }

    stack[pos] = x;
}
void insrtAfter(int val)
{
    int x, pos;
    printf("enter the element\n");
    scanf("%d", &x);
    for (int j = top; j > -1; j--)
    {
        if (stack[j] == val)
        {
            pos = j;
            printf("position %d\n", pos);
        }
    }
    top++;
    for (int i = top; i >= pos; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[pos] = x;
}
void insrtBefore(int val)
{
    int x, pos;
    printf("enter the element\n");
    scanf("%d", &x);
    for (int j = top; j > -1; j--)
    {
        if (stack[j] == val)
        {
            pos = j;
        }
    }
    top++;
    for (int i = top; i > pos; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[pos + 1] = x;
}
void search() // Searching For a specific element as user input
{
    int val;
    printf("Enter The Element You wanna search\n");
    scanf("%d", &val);
    for (int j = top; j > -1; j--)
    {
        if (stack[j] == val)
        {
            printf("Element Found at position %d\n", j);
        }
        else
        {
            printf("Element not found\n");
        }
    }
}

void sort()
{

    int i, j, temp;
    printf("Enter your choice:\n");

    for (i = 0; i < top; i++)
    {
        for (j = 0; j < top - i - 1; j++)
        {
            if (stack[j] > stack[j + 1])
            {
                temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
}

void show()
{
    for (int i = top; i > -1; i--)
    {
        printf("values are %d\n", stack[i]);
    }
}

int main()
{
    printf("animesh maiti 2130006\n");
    int ch, n, element;
    printf("enter the number of elemwnts\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        push();
    }
    printf("top is %d\n", top);
    printf("n1.Display the contents of the stack\n");
    printf("n2.insersertion at begining\n");
    printf("n3.insersertion at the end\n");
    printf("n4.insersertion after element\n");
    printf("n5.insersertion before element\n");
    printf("n6.shorting\n");
    printf("n7.search element\n");
    while (1)
    {
        printf("enter the menue number\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("n1.Display the contents of the stack\n");
            show();
            break;
        case 2:
            printf("n2.insersertion at begining\n");
            push();
            printf("top is %d\n", top);
            break;
        case 3:
            printf("n3.insersertion at the end\n");
            insertion(0);
            printf("top is %d\n", top);
            break;
        case 4:
            printf("n4.insersertion after element\n");
            printf("enter the element where you want to insert\n");
            scanf("%d", &element);
            insrtAfter(element);
            printf("top is %d\n", top);
            break;
        case 5:
            printf("n5.insersertion before element\n");
            printf("enter the element where you want to insert\n");
            scanf("%d", &element);
            insrtBefore(element);
            printf("top is %d\n", top);
            break;
        case 6:
            printf("n6.shorting\n");
            sort();
            break;
        case 7:
            printf("n7.search element\n");
            search();
            break;

        default:
            printf("wrong choce\n");
            break;
        }
    }
    return 0;
}