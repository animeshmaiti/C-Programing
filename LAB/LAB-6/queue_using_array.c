#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enque(int element)
{
    if (rear >= N - 1)
    {
        printf("queue overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = element; 
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}
void isEmpty()
{
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else
        printf("queue is not empty\n");
}
int isFull()
{
    if (rear >= N - 1)
        printf("queue is full\n");
    else
        printf("queue is not full\n");
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    for (int i = front; i <= rear; i++)
    {
        printf("element is %d\n", queue[i]);
    }
    
}
void deque()/*after stack full if you dequeue than you also cannot enqueue new data
            because stack is full but this problem will solved in circular queue*/ 
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else if (front == rear)
    {
        printf("deque element is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("deque element is %d\n", queue[front]);
        front++;
    }
}
void peek(){
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    printf("peek element is %d\n",queue[front]);
    
}

int main()
{
    int choice, element;
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display of elements\n");
    printf("5.IsEmpty\n");
    while (1)
    {
        printf("enter your choice\n");
        scanf("%d", &choice);
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
            printf("chose a valid menu\n");
            break;
        }
    }
    return 0;
}