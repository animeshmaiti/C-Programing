// WAP to create a Circular Doubly Linked List of n nodes and display the linked list by
// using suitable user-defined functions to create and display operations.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *tail = NULL, *head = NULL;

void create(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL)
    {
        head = tail = ptr;
        head->next = head;
        head->prev = head;
    }
    else
    {
        tail->next = ptr;
        ptr->prev = tail;
        ptr->next = tail;
        head->prev = ptr;
        tail = ptr;
    }
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while (temp != tail)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

int main()
{
    int n,element;
    printf("Arnab pal 213099\n");
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&element);
        create(element);
    }
    printf("the list is\n");
    display();
    return 0;
}