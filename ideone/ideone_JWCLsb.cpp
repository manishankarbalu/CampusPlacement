// C++ program to count all nodes having k leaves
// in subtree rooted with them
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node  */
struct Node
{
    int data ;
    struct Node * left, * right ;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node * newNode(int data)
{
    struct Node * node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
int kLeaves(Node* node,int k)
{
	if(node==NULL) return 0;
 
	if(node->left==NULL && node->right==NULL) return 1;
 
	int total=kLeaves(node->left,k)+kLeaves(node->right,k);
	if(total==k)
	     cout<<node->data<<" ";
	return total;
}
 
// Driver program to run the case
int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(4);
    root->left->left  = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(60);
    root->left->right->right = newNode(61);
    root->left->left->left  = newNode(9);
    root->left->left->right  = newNode(10);
    root->right->right = newNode(8);
    root->right->left  = newNode(7);
    root->right->left->left  = newNode(11);
    root->right->left->right  = newNode(12);
 
    kLeaves(root, 4);
 
    return 0;
}