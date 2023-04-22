#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cof;
    int exp;
    struct node *next;
};
struct node *head=NULL, *temp = NULL;
void create()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter the coefficient and exponent : ");
    scanf("%d%d", &ptr->cof, &ptr->exp);
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        temp = ptr;
    }
    else
    {
        temp->next = ptr;
        temp = ptr;
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->cof, temp->exp);
        temp = temp->next;
       if (temp!=NULL)
       {
         printf(" + ");
       }
              
    }
}

int main()
{
    int n;
    printf("enter the number of nodes\n");
    scanf("%d", &n);
    printf("enter the polynomial\n");
    for (int i = 0; i < n; i++)
    {
        create();
    }

    printf("the equation is :\n");
    display();

    return 0;
}
