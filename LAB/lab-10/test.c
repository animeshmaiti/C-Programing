#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;
struct node *head = NULL;
struct stack
{
    int size;
    char *arr;
};
struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};
int stackTop(struct stack *sp)
{
    return sp->arr[top];
}

int isEmpty(struct stack *ptr)
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        top++;
        ptr->arr[top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
            }
    else
    {
        char val = ptr->arr[top];
        top--;
        return val;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    return (node);
}
void InOrder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        InOrder(node->left);
        printf("%c ", node->data);
        InOrder(node->right);
    }
} // LNR

void PreOder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        printf("%c ", node->data);
        PreOder(node->left);
        PreOder(node->right);
    }
} // NLR

void PostOrder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        PostOrder(node->left);
        PostOrder(node->right);
        printf("%c ", node->data);
    }
} // LRN
void pushT(struct node *x)
{
    if (head == NULL)
        head = x;
    else
    {
        x->next = head;
        head = x;
    }
}

struct node *popT()
{
    // Popping out the top most[ pointed with head] element
    struct node *p = head;
    head = head->next;
    return p;
}
int main()
{
    char infix[] = {'P', '*', 'Q', '+', 'P', '*', 'R', '+', 'Q', '*', 'R'};//charecter array
    char *postfix = infixToPostfix(infix);
    int size= sizeof(infix);
    for (int i = 0; i < size; i++)
    {
        printf("%c ",postfix[i]);
    }
    infixToPostfix(infix);
    struct node *x, *y, *z;
    for (int i = 0; i < size; i++)
    {
        // if read character is operator then popping two
        // other elements from stack and making a binary
        // tree
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*')
        {
            z = newNode(postfix[i]);
            x = popT();
            y = popT();
            z->left = y;
            z->right = x;
            pushT(z);
        }
        else
        {
            z = newNode(postfix[i]);
            pushT(z);
        }
    }
    printf("\ninfix = ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ",infix[i]);
    }
    printf("\n");
    printf("The Inorder Traversal of Expression Tree: ");
    InOrder(z);
    printf("\n");
    PreOder(z);
    printf("\n");
    PostOrder(z);
    
    return 0;
}
