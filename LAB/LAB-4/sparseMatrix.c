// C program for Sparse Matrix Representation
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node to represent sparse matrix
struct node
{
    int value;
    int rowPos;
    int columnPos;
    struct node *next;
};
struct node *head=NULL, *temp = NULL;
// Function to create new node
void createNewNode(int nonZeroElement,
                   int rowIndex, int columnIndex)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = nonZeroElement;
    newNode->rowPos = rowIndex;
    newNode->columnPos = columnIndex;
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

// This function prints contents of linked list
void PrintList()
{
    struct node *row, *column, *element;
    element = row = column = head;

    printf("row position: ");
    while (row != NULL)
    {
        printf("%d ", row->rowPos);
        row = row->next;
    }
    printf("\n");

    printf("column_postion: ");
    while (column != NULL)
    {
        printf("%d ", column->columnPos);
        column = column->next;
    }
    printf("\n");
    printf("Value: ");
    while (element != NULL)
    {
        printf("%d ",element->value);
       element =element->next;
    }
    printf("\n");
}

// Driver of the program
int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatric[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ",sparseMatric[i][j]);
        }
        printf("\n");
    }
    

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatric[i][j] != 0) // Pass only those values which are non - zero
                createNewNode(sparseMatric[i][j], i, j);

    PrintList();

    return 0;
}
