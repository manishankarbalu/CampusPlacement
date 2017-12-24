#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int CountNodes(struct node* root)
{
	if(root==NULL) return 0;
	
	 return CountNodes(root->left)+CountNodes(root->right)+1;
	
}
int height(struct node* root)
{

   if(root==NULL) return 0;
    
   int lh=height(root->left);
   int rh=height(root->right);
  if(lh>rh)
    return lh+1;
  else
     return rh+1;

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
 
/* Driver program to test above functions*/
int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);
  //int h=height(root);
  printf("%d %d ",CountNodes(root),height(root));
  return 0;
}
