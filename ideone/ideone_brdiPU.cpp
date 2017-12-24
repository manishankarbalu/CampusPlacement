// A C++ program to find the deepest left leaf in a given binary tree
#include <stdio.h>
#include <iostream>
using namespace std;
 
struct Node
{
    int val;
    struct Node *left, *right;
};
 
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}
 
void deepestLLeafNode(struct Node* root,int level,int* maxlevel,int* value)
{
  if(!root)
  	return;
  if(level>*maxlevel)
  {
  	*maxlevel=level;
  	 
  	 	  *value=root->val;
  }
deepestLLeafNode(root->left,level+1,maxlevel,value);
deepestLLeafNode(root->right,level+1,maxlevel,value);


}

void findDeepestLLeafNode(struct Node* root)
{
	int level=1,maxlevel=0,value=0;
    deepestLLeafNode(root,level,&maxlevel,&value);	
    cout<<value;
}
 
// Driver program to test above function
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    findDeepestLLeafNode(root);
 
    return 0;
}