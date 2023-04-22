#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *temp = NULL, *head;

void TraversForward()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void TraversBackward()
{
    struct node *last = temp;
    while (last != NULL)
    {
        printf("element : %d\n", last->data);
        last = last->prev;
    }
}
void create(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        temp = ptr;
    }
    else
    {
        temp->next = ptr;
        ptr->prev = temp;
        temp = ptr;
    }
}
void insertAtIndex(int index, int data)
{
    struct node *ptr;
    int i;
    ptr = (struct node *)malloc(sizeof(struct node));
    temp = head;
    for (i = 0; i < index-1; i++)
    {
        temp = temp->next;
    }
    ptr->data = data;
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next = ptr;
    temp->next->prev = ptr;
    printf("node inserted\n");
}


void deleteAtIndex(int index)
{
    struct node *p = head;
    struct node *q = head->next; // q is refering after headnode's next node
    int i = 0;

    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next; // p next referring q next. where q next is next of p next
    q->next->prev = p;
    free(q);
}
void checkEmpty()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("the list is empty\n");
    }
    else
        printf("the list is not empty\n");
}
int countNodes()
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
void reverse()
{
    struct node *current = head;
    struct node *nextnode = NULL;
    while (current != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = temp;
    temp = current;
}
void search(int data)
{
    struct node *ptr;
    int i = 0;
    ptr = head;

    while (ptr->data!=data && ptr->next!= NULL)
    {
        i++;
        ptr = ptr->next;
    }
    if (ptr->data == data)
    {
        printf("item found at index %d \n", i);
        
    }
    else
    {
        printf("item is not found\n");
    }
}

int main()
{
    printf("Arnab pal 213099\n");
    int ch, index, data, element, n;
    printf("enter the number of nodes\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        create(element);
    }
    printf("n1.Traverse forward,\n");
    printf("n2.Traverse backward,\n");
    printf("n3Check if the list is empty\n");
    printf("n4.Insert node at a certain position\n");
    printf("n5.Delete node at a certain position\n");
    printf("n6.Count Nodes\n");
    printf("n7.Reverse List\n");
    printf("n8.Search List\n");
    while (1)
    {
        printf("enter the menu no.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Traverse forward,\n");
            TraversForward();
            break;
        case 2:
            printf("Traverse backward,\n");
            TraversBackward();
            break;
        case 3:
            printf("Check if the list is empty\n");
            checkEmpty();
            break;
        case 4:
            printf("Insert node at a certain position\n");
            printf("enter the index\n");
            scanf("%d", &index);
            printf("enter the data\n");
            scanf("%d", &data);
            insertAtIndex(index, data);
            break;
        case 5:
            printf("Delete node at a certain position\n");
            printf("enter the index\n");
            scanf("%d", &index);
            
            deleteAtIndex(index);

            break;
        case 6:
            printf("Count Nodes\n");
            printf("node count is: %d \n", countNodes());
            break;
        case 7:
            printf("Reverse List\n");
            reverse();
            break;
        case 8:
            printf("Search List\n");
            printf("enter the element to search\n");
            scanf("%d", &element);
            search(element);
            break;

        default:
            printf("wrong choice\n");
            break;
        }
    }

    return 0;
}