// C++ program to find minimum depth of a given Binary Tree
#include<bits/stdc++.h>
using namespace std;
 
// A BT Node
struct Node
{
    int data;
    struct Node* left, *right;
};
void minDepthUtil(Node* root,int &min,int curmin)
{
	if(!root)
	   return;
	if(!root->left && !root->right)
	   {
	   	if(min>curmin)
	   	   min=curmin;
	   }
	   
	minDepthUtil(root->left,min,curmin+1);
	minDepthUtil(root->right,min,curmin+1);
}
 
int minDepth(Node *root)
{
   int min=INT_MAX;
   minDepthUtil(root,min,1);
   return min;
}
 
// Utility function to create new Node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    /*Node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);*/
    Node *root        = newNode(10);
    root->left        = newNode(2);
    root->right       = NULL;
    cout << minDepth(root);
    return 0;
}