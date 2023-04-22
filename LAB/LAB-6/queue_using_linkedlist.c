// Write a menu-driven program to implement Queue operations such as Enqueue, Dequeue, Peek, Display of 
// elements, IsEmpty using a linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*front =NULL,*rear=NULL;
void enqueue(int),dequeue();
void enqueue(int x)
{
    struct node*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    if (front==NULL && rear== NULL )
    {
        rear=front=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
    
}

void dequeue(){
    struct node*temp=front;
    if (front==NULL && rear== NULL)
    {
        printf("queue is empty\n");
    }else
    {
        printf("dequeued element is: %d\n",front->data);
        front=front->next;
        free(temp);
    }   
}

void display(){
    struct node*temp;
    if (front==NULL && rear== NULL)
    {
        printf("queue is empty\n");
    }else
    {
        printf("elements are:");
        temp=front;
        while (temp !=NULL)
        {
            printf(" %d",temp->data);
            temp= temp->next;
        }
        printf("\n");
        
    }
}

void isEmpty(){
    if (front==NULL && rear== NULL)
    {
        printf("queue is empty\n");
    }else
    {
        printf("queue is not empty\n");
    }
}
void peek(){
    if (front==NULL && rear== NULL)
    {
        printf("queue is empty\n");
    }
    else{
        printf("peek element is %d\n",front->data);
    }
}

int main(){
    printf("animesh maiti 2130006\n");
    int choice,element;
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display of elements\n");
    printf("5.IsEmpty\n");
    printf("6.Exit the loop\n");

    while (1)
    {
        printf("enter your choice\n");
        scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("enter element\n");
        scanf("%d",&element);
        enqueue(element);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    case 5:
        isEmpty();
        break;
    case 6:
        printf("you are exiting this loop\n");
        break;
    default:
        printf("ivalid choice\n");
        break;
    }
    if (choice==6)
    {
        break;
    }
       
    } 
    return 0;
}