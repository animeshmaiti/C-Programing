#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

char pop()
{
    char item;

    if (top < 0)
    {
        printf("stack under flow: invalid infix expression");
        getchar();
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char symbol)
{
    if (symbol == '*' || symbol == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);

            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;

        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }

    postfix_exp[j] = '\0';
}

char expStack[SIZE], top2 = -1;

struct Node
{
    char data;
    struct Node *lChild;
    struct Node *rChild;
} *ptr, *ptr2, *root = NULL, *temp = NULL, *temp2 = NULL;

void create_node(char exp[])
{
    for (int i = 0; i < 11; i++)
    {
        int flag = is_operator(exp[i]);

        if (flag == 0)
        {
            expStack[++top] = exp[i];
        }
        else if (flag == 1)
        {
            if (i == 10)
            {
                ptr = (struct Node *)malloc(sizeof(struct Node));
                ptr->data = exp[i];
                root = ptr;
                root->lChild = temp2;
                root->rChild = temp;
            }
            else
            {
                ptr = (struct Node *)malloc(sizeof(struct Node));
                ptr->data = exp[i];
                if (top > -1)
                {
                    ptr2 = (struct Node *)malloc(sizeof(struct Node));
                    ptr2->data = expStack[top--];
                    ptr2->lChild = NULL;
                    ptr2->rChild = NULL;
                    ptr->rChild = ptr2;
                    ptr2 = (struct Node *)malloc(sizeof(struct Node));
                    ptr2->data = expStack[top--];
                    ptr2->lChild = NULL;
                    ptr2->rChild = NULL;
                    ptr->lChild = ptr2;
                }
                if (temp)
                    temp2 = ptr;
                else
                    temp = ptr;
                if (temp && temp2)
                {
                    ptr->lChild = temp;
                    ptr->rChild = temp2;
                    temp = NULL;
                    temp2 = NULL;
                }
                if (i == 6)
                    temp2 = ptr;
            }
        }
    }
}

int main()
{
    char exp[] = "P*Q+P*R+Q*R";
    char postfixExp[SIZE];

    InfixToPostfix(exp, postfixExp);

    printf("\n%s", postfixExp);

    create_node(exp);

    return 0;
}