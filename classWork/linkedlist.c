#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head, *temp = NULL;

void create(int data)
{

	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	// head=ptr;
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		temp = newNode;
	}
	else
	{
		temp->next = newNode;
		temp = newNode;
	}

}
void traverse()
{
	struct node *ptr = head;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}
int main()
{

	create(2);
	create(4);
	create(67);
	create(45);
	traverse();
	return 0;
}