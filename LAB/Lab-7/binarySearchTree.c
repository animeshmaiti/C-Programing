#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    } // LNR
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    } // NLR
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    } // LRN
}

struct node *create(struct node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->data)
    {
        // printf("you entered the left child data of %d\n", root->data);
        root->left = create(root->left, val);
    }
    else if (val > root->data)
    {
        // printf("you entered the right child data of %d\n", root->data);
        root->right = create(root->right, val);
    }
    return root;
}

struct node *binarySearch(struct node *ptr, int val)
{
    if (ptr == NULL)
    {
        printf("not found\n");
        return NULL;
    }
    else if (ptr->data == val)
    {
        printf("item found\n");
    }
    else if (val < ptr->data)
    {
        return binarySearch(ptr->left, val);
    }
    else if (val > ptr->data)
    {
        return binarySearch(ptr->right, val);
    }
    return ptr;
}

int smallest(struct node *root)
{
    if (root->left == NULL)
        return root->data;
    return smallest(root->left);
}

int largest(struct node *root)
{
    if (root->right == NULL)
        return root->data;
    return largest(root->right);
}

struct node *smallestNode(struct node *node)
{
    struct node *current = node;

    //loop to find the left most leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int element)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (element < root->data)
    {
        root->left = deleteNode(root->left, element);
    }
    else if (element > root->data)
    {
        root->right = deleteNode(root->right, element);
    }
    else
    {
        // deletion node with one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //node with two child
        /*we can do 2 thing one is
        we can replace the node with in-order predececor(left sub-tree's largest valueNode)
        or in-order successor(right sub-tree's smallest value node)
        we are doing in-order sucessor method*/ 
        struct node *temp = smallestNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void main()
{
    struct node *root = NULL;
    int ch, element;
    printf("enter the root element\n");
    scanf("%d", &element);
    root = create(root,element); /*binary search tree alwayas start from root every time we create or insert a node it will 
    alwayas strat from root not from sub tree*/
    create(root, 3);
    create(root, 6);
    create(root, 4);
    create(root, 1);
    create(root, 10);
    create(root, 14);
    printf("1.create\n");
    printf("2.in-order traversal\n");
    printf("3.pre-order traversal\n");
    printf("4.post-order traversal\n");
    printf("5.Search element\n");
    printf("6.find smallest element\n");
    printf("7.find largest element\n");
    printf("8.deletion\n");
    printf("9.Quit\n");
    while (1)
    {
        printf("enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the elment to insert\n");
            scanf("%d", &element);
            create(root, element);
            break;
        case 2:
            inOrder(root);
            printf("\n");
            break;
        case 3:
            preOrder(root);
            printf("\n");
            break;
        case 4:
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("enter the element for search\n");
            scanf("%d", &element);
            binarySearch(root, element);
            break;
        case 6:
            printf("\nsmallest element is: %d\n", smallest(root));
            break;
        case 7:
            printf("largest element is: %d\n", largest(root));
            break;
        case 8:
            printf("enter the element\n");
            scanf("%d", &element);
            deleteNode(root, element);
            break;
        case 9:
            printf("you are exiting this loop\n");
            break;
        default:
            printf("enter a wright choice\n");
            break;
        }
        if (ch==9)
            break;
    }
}
