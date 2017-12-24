// C++ program to find depth of the deepest
// odd level node
#include<bits/stdc++.h>
using namespace std;
 
// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function to create a new node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
 
 
int height(Node *node)
{
    if(node==NULL) return 0;
 
    int lh=height(node->left);
    int rh=height(node->right);
    return lh>rh?lh+1:rh+1;
}
 
int main()
{
    /*   10
       /     \
     28       13
            /     \
          14       15
                  /  \
                 23   24
    Let us create Binary Tree shown in above example */
    Node *root  = newNode(10);
    root->left  = newNode(28);
    root->right = newNode(13);
 
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
 
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
 
 
    int t=height(root);
      if(t&1)
         cout<<t;
         else
             cout<<t-1;
 
    return 0;
}