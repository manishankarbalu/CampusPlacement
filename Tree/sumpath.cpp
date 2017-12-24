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
 void prints(int path[],int pathLen)
{
     for(int i=0;i<pathLen;i++)
           cout<<path[i]<<" ";
  cout<<endl;

}
void printPathsUtil(struct Node* root,int sum,int t,int path[],int pathLen)
{
	if(root==NULL) return;
	
	if(t!=sum)
	      { 
	     t+=root->key;cout<<t<<" ";
	     path[pathLen]=root->key;
           pathLen++ ;
	      }
	if(t==sum)
	{      
            cout<<"into";
           prints(path,pathLen);
        return;
	}
	else{
	printPathsUtil(root->left,sum,t,path,pathLen);
	
	printPathsUtil(root->right,sum,t,path,pathLen);
	}
}
 
void printPaths(struct Node* root,int sum)
{
	int path[10]={0,0,0,0,0,0,0,0,0,0};
	printPathsUtil(root,sum,0,path,0);
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
