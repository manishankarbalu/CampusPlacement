#include <stdio.h>
#include <stdlib.h>
 
// Binary Tree node
struct node
{
    int data;
    struct node* left, *right;
};
 
// A utility function to allocate a new tree node with given data
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left =  node->right = NULL;
    return (node);
}
 
// The main function that return difference between odd and even level
// nodes
int height(struct node* root)
{
	if(!root)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}

void calculateCount(struct node* root,int level,int* oddSum,int* evenSum,int choice)
{
    if(!root)
    	return;
    if(level==1)
    {
    	if(choice==1)
    		*evenSum+=root->data;
    	else
    		if(choice==0)
    			*oddSum+=root->data;
    return;
    }
    calculateCount(root->left,level-1,oddSum,evenSum,choice);
    calculateCount(root->right,level-1,oddSum,evenSum,choice);
}

void DifferenceInLevel(struct node* root)
{
	int h=height(root);
	int oddSum=0,evenSum=0;
	for(int i=1;i<=h;i++)
	{
		if(i%2==0)
           calculateCount(root,i,&oddSum,&evenSum,1);
	    else
	       calculateCount(root,i,&oddSum,&evenSum,0);  
	}
	printf("difference is %d  : ",(evenSum-oddSum));
}

 
// Driver program to test above functions
int main()
{
    struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
    DifferenceInLevel(root);
    getchar();
    return 0;
}