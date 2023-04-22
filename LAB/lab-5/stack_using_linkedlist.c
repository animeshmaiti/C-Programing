#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; // assign value to the node
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
    printf("Node is Inserted\n");
}
void isEmpty()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
        printf("stack is not empty\n");
}

void pop()
{
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("poped element is %d\n",top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    // Display the elements of the stack
    struct Node *temp = top;
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("The stack is \n");
        while (temp->next != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main()
{
    printf("Arnab pal 213099\n");
    int choice, value,n,element;
    printf("enter the number of element\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&element);
        push(element);
    }
    
    printf("1. Push\n2. Pop\n3. Display\n4. isEmpty\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("check is empty\n");
            isEmpty();
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
