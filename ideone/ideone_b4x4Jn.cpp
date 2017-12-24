/* program for boundary traversal of a binary tree */
#include <stdio.h>
#include <stdlib.h>
#include<vector>
using namespace std;
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left, *right;
};
 

void leftTraversal(struct node* root,vector<int>& v)
{
    if(!root && !root->left && !root->right)
    	return;
    v.push_back(root->data);
    leftTraversal(root->left,v);
}

void rightTraversal(struct node* root,vector<int>& v)
{
if(!root && !root->left && !root->right)
    	return;
    v.push_back(root->data);
    leftTraversal(root->right,v);
}

void leafTraversal(struct node* root,vector<int>& v)
{

     if(!root)
     	return;
     if(!root->left && !root->right)
     	v.push_back(root->data);
     leftTraversal(root->left,v);
     leftTraversal(root->right,v);
}

void boundaryTraversal(struct node* root)
{
	if(!root)
		return;
	vector<int> v;
	v.push_back(root->data);
	leftTraversal(root->left,v);
	rightTraversal(root->right,v);
	leftTraversal(root,v);
	for(int i=0;i<v.size();i++)
	   printf("%d ",v[i]);
}
// A utility function to create a node
struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    boundaryTraversal( root );
 
    return 0;
}