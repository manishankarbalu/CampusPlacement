/* Program to print all nodes which are at distance k from a leaf */
#include <iostream>
using namespace std;
#define MAX_HEIGHT 10000
 
struct Node
{
	int key;
	Node *left, *right;
};
 
/* utility that allocates a new Node with the given key */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}
void printT(int path[],int pathLen)
{
	for(int i=0;i<pathLen;i++)
	    cout<<path[i]<<" ";
cout<<"\n";
}
void printRootToLeafUtil(struct Node* root,int path[],int pathLen,int k)
{
	if(root==NULL) return;
 
	path[pathLen++]=root->key;
 
	if(root->left==NULL && root->right==NULL)
	{
		cout<<"dist : "<<path[pathLen-k-1];
		printT(path,pathLen);
	}
	printRootToLeafUtil(root->left,path,pathLen,k);
	printRootToLeafUtil(root->right,path,pathLen,k);
}
 
void printRootToLeaf(struct Node* root)
{
	int path[10];int pathLen=0;
     printRootToLeafUtil(root,path,pathLen,2);
}
 
/* Driver program to test above functions*/
int main()
{
	// Let us create binary tree given in the above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
 
	cout << "Nodes at distance 2 are: ";
printRootToLeaf(root);
	return 0;
}