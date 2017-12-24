#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};


int prev;bool flag=true;
bool check(int val)
{  printf("%d",prev);
	if(flag)
	{
		prev=val;
		flag=false;
		return true;
	}
	if(prev>=val) return false;
	prev=val;
	return true;
	
}

bool isBST(struct node* root)
{
	if(!root)
	 return true;
    return isBST(root->left)&&check(root->data)&&isBST(root->right);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
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
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
   struct node *root1 = newNode(4);
  root1->left        = newNode(7);
  root1->right       = newNode(5);
  root1->left->left  = newNode(1);
  root1->left->right = newNode(3); 

  if(isBST(root))
    printf("Is BST\n");
  else
    printf("Not a BST\n");
  if(isBST(root1))
    printf("Is BST");
  else
    printf("Not a BST");
    
  getchar();
  return 0;
}  
