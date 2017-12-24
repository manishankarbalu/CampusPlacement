#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
 int isLeaf(struct node* root)
{
	if(!root->left && !root->right)
		return 1;
	else
		return 0;
}
/* A utility function to get the sum of values in tree with root
  as root */
int checkSumTree(struct node* root)
{
	if(!root || isLeaf(root))
		return 1;
	int lnum,rnum;
	if(checkSumTree(root->left) && checkSumTree(root->right))
     {
     	if(root->left==NULL)
     		lnum=0;
     	else
     		if(isLeaf(root->left))
     			lnum=root->left->data;
     		else
     			lnum=root->left->data * 2;

     	if(root->right==NULL)
     		rnum=0;
     	else
     		if(isLeaf(root->right))
     			rnum=root->right->data;
     		else
     			rnum=root->right->data * 2;

     	return(root->data==lnum+rnum);
     }
     return 0;
}
/*
 Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
/* Driver program to test above function */
int main()
{
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
   if(checkSumTree(root))
      printf("sum tree");
      else
      printf("not a sum tree");
    getchar();
    return 0;
}