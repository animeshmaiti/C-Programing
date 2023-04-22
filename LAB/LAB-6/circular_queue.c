// Write a menu-driven program to implement Circular Queue operations such as Enqueue, Dequeue, Peek,
// Display of elements, IsEmpty, and IsFull using a static array.
#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enque(int data){
    if (front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else if ((rear+1)%N==front)
    {
        printf("queue is full\n");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=data;
    }
}
void deque(){
    if (front==-1 && rear==-1)
    {
        printf("queue is empty\n");
    }
    else if (front==rear)
    {
        printf("deque element is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("deque element is %d\n", queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    int i=front;
    if (front==-1 && rear==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue is: ");
        while (i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[i]);
        printf("\n");        
    }
}

void peek(){
    printf("peek element is: %d\n",queue[front]);
}
void isEmpty(){
    if (front==-1 && rear==-1)
    {
        printf("queue is empty\n");
    }
    else
    printf("queue is not empty\n");
}
void isFull(){
    if ((rear+1)%N==front)
    {
        printf("queue is full\n");
    }
    else
    printf("queue is not full\n");
}
int main(){
    printf("animesh maiti 2130006\n");
    int choice,element;
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display of elements\n");
    printf("5.IsEmpty\n");
    while (1)
    {
    printf("enter a choice\n");
    scanf("%d",&choice);           
    switch (choice)
    {
    case 1:
        printf("enter element\n");
        scanf("%d",&element);
        enque(element);
        break;
    case 2:
        deque();
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
    
    default:
    printf("chose a valid number\n");
        break;
    }
    }
    
    return 0;
}