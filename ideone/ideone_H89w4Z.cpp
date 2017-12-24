// C++ program to print all paths begiinning with
// root and sum as given sum
#include<bits/stdc++.h>
using namespace std;
 
// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function to create a new node
Node* newnode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 bool checkArray(int ints[], int len,int match,int sum)
{
  int i;
  for (i=0; i<len; i++) {
   if(ints[i]+match==sum)
       return true;
  }
  return false;
} 
 
void printPathsRecur(Node*node, int sum, int path[],int pathLen)
{
	 if (node==NULL) return;
 
 if(pathLen<1)
 { //t+=node->key;
 	path[pathLen] = node->key;
  pathLen++;
 }
else
  {
    if(checkArray(path, pathLen, node->key,sum))
    {
    	cout<<"yes found";
    	return;
    }
    else
    {
    	path[pathLen] = node->key;
         pathLen++;
    }
  }
 
 
    printPathsRecur(node->left,sum, path, pathLen);
    printPathsRecur(node->right,sum, path, pathLen);
 
}
 
// Wrapper over printPathsUtil
void isPathSum(Node *root)
{
   int path[10];
    int sum=root->key;
    printPathsRecur(root->left, sum, path, 0);
    printPathsRecur(root->right, sum, path, 0);
}
 
// Driver program
int main ()
{
 
 
    struct Node *root = newnode(14);
    root->left    = newnode(5);
    root->right   = newnode(4);
    root->left->left = newnode(9);
    root->left->right = newnode(7);
    root->left->right->left = newnode(1);
    root->left->right->right = newnode(12);
    root->left->right->right->right = newnode(2);
    root->right->right = newnode(11);
    root->right->right->left = newnode(3);
    isPathSum(root);
    return 0;
 
 
}