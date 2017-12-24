#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. */
struct node* newNode(int data) 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data  = data;
  node->left  = NULL;
  node->right = NULL;
   
  return(node);
}
 
/* Give a binary search tree and a number, 
inserts a new node with the given number in 
the correct place in the tree. Returns the new 
root pointer which the caller should then use 
(the standard trick to avoid using reference 
parameters). */
struct node* insert(struct node* node, int data) 
{
  /* 1. If the tree is empty, return a new,     
      single node */
  if (node == NULL) 
    return(newNode(data));  
  else
  {
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data) 
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
   
    /* return the (unchanged) node pointer */
    return node; 
  }
}
 
/* Given a non-empty binary search tree,  
return the minimum data value found in that 
tree. Note that the entire tree does not need 
to be searched. */
int KthEle(struct node* root,int k)
{
	stack<struct node*> s;
	struct node* ptr=root,*temp;
//	cout<<"enter";
	while(ptr)
	{   //cout<<ptr->data;
		s.push(ptr);
		ptr=ptr->left;
	}
	
//	cout<<"push";
	while((ptr=s.top()) && --k)
	{     s.pop();
	    //  cout<<ptr->data<<' ';
	 if(ptr->right!=NULL)
	   {   ptr=ptr->right;
		  // cout<<ptr->data<<' ';
		  while(ptr)
	      {
		   s.push(ptr);
		   cout<<ptr->data;
		   ptr=ptr->left;
		   
	      } 
	    }
	}
	return (ptr)?ptr->data:0;
}
 
/* Driver program to test sameTree function*/   
int main()
{
  struct node* root = NULL;
  root = insert(root, 20);
  insert(root, 8);
  insert(root, 22);
  insert(root, 4);
  insert(root, 12);
  insert(root, 10);
  insert(root, 14);
  int k=2;
  printf("\n %d Minimum value in BST is %d",k, KthEle(root,k));
  getchar();
  return 0;    
}