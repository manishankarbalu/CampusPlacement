// C++ program to find if there is a subtree with
// given sum
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
};
 
/* utility that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newnode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right  = NULL;
    return (node);
}
 
bool sumSubtree(Node* root,int *t,int sum)
{
	if(root==NULL) {return false; *t=0;}
	int ls=0,rs=0;
 
	return(sumSubtree(root->left,&ls,sum)||sumSubtree(root->right,&rs,sum)||((*t=ls+rs+root->data)==sum));
 
}
 
 
int main()
{
    struct Node *root = newnode(8);
    root->left    = newnode(5);
    root->right   = newnode(4);
    root->left->left = newnode(9);
    root->left->right = newnode(7);
    root->left->right->left = newnode(1);
    root->left->right->right = newnode(12);
    root->left->right->right->right = newnode(2);
    root->right->right = newnode(11);
    root->right->right->left = newnode(3);
    int sum = 3;
    int s=0;
    if (sumSubtree(root, &s, sum))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}