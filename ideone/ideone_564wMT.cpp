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
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
void printPathsUtil(struct Node* root,int sum,int t,vector<int> path)
{
	if(root==NULL) return;
 
	if(t!=sum)
	      { 
	  t+=root->key;//cout<<t<<" ";
	     path.push_back(root->key);
	      }
	if(t==sum)
	{
		for(int i=0;i<path.size();i++)
		   cout<<path[i]<<" ";
		   cout<<endl;
		  return;
	}
	if(root->left)
	printPathsUtil(root->left,sum,t,path);
	if(root->right)
	printPathsUtil(root->right,sum,t,path);
	path.pop_back();
 
}
 
void printPaths(struct Node* root,int sum)
{
	//int path[100];int pathLen=0,t=0;
	vector<int> path;int t=0;
	printPathsUtil(root,sum,t,path);
}
// Driver program
int main ()
{
    /*   10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24*/
    Node *root  = newNode(10);
    root->left  = newNode(28);
    root->right = newNode(13);
 
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
 
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
 
    int sum = 38;
 
    printPaths(root, sum);
 
    return 0;
}