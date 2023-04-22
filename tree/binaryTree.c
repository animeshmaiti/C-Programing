#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node*create(){
    int x;
    struct node* newNode =(struct node*)malloc(sizeof(struct node));
    printf("enter the data(-1 for no node)\n");
    scanf("%d",&x);
    if (x==-1)
    {
        return 0;
    }
    newNode->data=x;
    printf("enter the left child data of %d\n",x);
    newNode->left=create();/*call create function recusively, this func call untill x==-1*/
    printf("enter the right child data of %d\n",x);
    newNode->right=create();//this function call after x==-1 one time
    return newNode;
}
void preOrder(struct node*root){
    if (root == NULL)
    {
        return;
    }
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}//NLR
void inOrder(struct node*root){
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}//LNR
void postOrder(struct node*root){
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}//LRN

void main(){
    struct node*root;
    root=NULL;
    root=create();
    preOrder(root);
    inOrder(root);
    postOrder(root);
}
