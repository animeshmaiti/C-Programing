#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp = NULL;
void traverse()
{
    struct node *ptr = head;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void create(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
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
void insertAtIndex(int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    ptr->data = data;
    while (i != index - 1)
    {
        p = p->next; // p is refering where the insertion is happen
        i++;
    }

    ptr->next = p->next; // linking p to new node(ptr)
    p->next = ptr;       // unlink

    // return head;
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
    free(q);
    // return head;
}
int countNodes()
{
    int count = 0;
    // Node current will point to head
    struct node *ptr = head;

    while (ptr != NULL)
    {
        // Increment the count by 1 for each node
        count++;
        ptr = ptr->next;
    }
    return count;
}
void searchElement(int value)
{
    int count = 0;
    struct node *ptr = head;

    while (ptr->data != value && ptr->next != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    if (ptr->data == value)
    {
        printf("element is found at index %d\n", count);
    }
    else
    {
        printf("element is not in the list\n");
    }
}
void reverse()
{
    
    struct node* prev = NULL;
    struct node* current =head;
    struct node* nextnode=NULL;
    while (current != NULL) {
        // Store next
        nextnode = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = nextnode;
    }
    head = prev;
}
void deleteByKey( int key)
{
    // Store head node
    struct node *temp =head,*prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        temp = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

int main()
{

    int ch, n, index, data,element,count;
    printf("enter the number of elements\n");
    scanf("%d",&count);
    printf("enter the elements\n");
    for (int i = 0; i <count; i++)
    {
        scanf("%d",&element);
        create(element);
    }
    

    printf("Arnab pal 213099\n");
    printf("n1.Traversal of the list\n");
    printf("n2. Check the empty list\n");
    printf("n3. insert a node at a certain position\n");
    printf("n4. Delete a node at certain position\n");
    printf("n5. delete a node for the given key\n");
    printf("n6. Count the total number of nodes\n");
    printf("n7. search for  an element in the linked list\n");
    printf("n8. Reverse the sequence elements in a list\n");
    while (1)
    {
        printf("enter the menu no.\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("n1.Traversal of the list\n");
            traverse();
            break;
        case 2:
            printf("n2. Check the empty list\n");
            checkEmpty();
            break;
        case 3:
            printf("n3. insert a node at a certain position\n");
            printf("enter the data and index want to insert\n");
            scanf("%d %d", &data, &index);
            insertAtIndex(data, index);
            break;
        case 4:
            printf("n4. Delete a node at certain position\n");
            printf("enter the index number that want to delete\n");
            scanf("%d", &index);
            deleteAtIndex(index);
            break;
        case 5:
            printf("n5. delete a node for the given key\n");
            printf("enter the key want to delete\n");
            scanf("%d",&element);
            deleteByKey(element);
            break;
        case 6:
            printf("n6. Count the total number of nodes\n");
            printf("the total node number is: %d\n", countNodes());
            break;
        case 7:
            printf("n7. search for  an element in the linked list\n");
            printf("enter the element\n");
            scanf("%d", &n);
            searchElement(n);
            break;
        case 8:
            printf("n8. Reverse the sequence elements in a list\n");
            reverse();
            break;

        default:
            printf("wrong choice\n");
            break;
        };
    }
    return 0;
}
