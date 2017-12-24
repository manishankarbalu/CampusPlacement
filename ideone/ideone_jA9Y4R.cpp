#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left, *right;
};
 
/* function to create a new node of tree and returns pointer */
struct node* newNode(int data);
 
/* returns max of two integers */
int max(int a, int b);
 
/* function to Compute height of a tree. */
int height(struct node* node);
 
/* Function to get diameter of a binary tree */
int diameter(struct node * root,int *height)
{
	if(!root)
	  {
	  	*height=0;
	  	return 0;
	  }
//	if(!root->left && !root->right)
//	  return 1;
	int lh=0,rh=0,ld=0,rd=0;
	
	ld=diameter(root->left,&lh);
	rd=diameter(root->right,&rh);
	
	*height=max(lh,rh)+1;
	
	return max(lh+rh+1,max(ld,rd));
	
}
   
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  int height=0;
  printf("Diameter of the given binary tree is %d\n", diameter(root,&height));
 
  getchar();
  return 0;
}