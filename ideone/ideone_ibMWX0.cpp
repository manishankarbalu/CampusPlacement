#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
int max(int a,int b)
{
	return (a>b)?a:b;
}
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
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
 
int largestBST(struct node* root, int *maxi,int *lh,int *rh,bool f)
{
	if(!root)
	  return 0;
	if(!root->left && !root->right)
	 { *lh=1;*rh=1;return root->data;}
	 // int lh=0,rh=0;
	int l=largestBST(root->left,maxi,lh,rh,true);
	int r=largestBST(root->right,maxi,lh,rh,false);
	printf("root %d l %d r %d",root->data,l,r);
	
	if(l<root->data && root->data<r)
	   	{
	   		*maxi=(*maxi>*lh+*rh+1)?*maxi:*lh+*rh+1;
	   	 if (f)*lh=*maxi;else *rh=*maxi;
	   	}
	   	else
	   	  if(f)*lh=1;else *rh=1;
	   	printf("maxi %d\n",*maxi);
	  return root->data;
}

int findLargestBST(struct node *p, int min, int max, int &maxNodes, 
                   struct node *& largestBST, BinaryTree *& child) {
  if (!p) return 0;
  if (min < p->data && p->data < max) {
    int leftNodes = findLargestBST(p->left, min, p->data, maxNodes, largestBST, child);
    BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;
    int rightNodes = findLargestBST(p->right, p->data, max, maxNodes, largestBST, child);
    BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;

   
    BinaryTree *parent = new BinaryTree(p->data);
    parent->left = leftChild;
    parent->right = rightChild;
       child = parent;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = parent;
    }
    return totalNodes;
  } else {
    findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
   
    return 0;
  }
}
  
 
/* Driver program to test above functions*/
int main()
{
    /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
/*  struct node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 */
 struct node *root = newNode(50);
  root->left        = newNode(30);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(45);
  //root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);
 
 /*struct node *root = newNode(5);
  root->left        = newNode(2);
  root->right       = newNode(4);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  //root->right->left  = newNode(55);
  */
  
  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
 45     65    80
  */
  int maxi=0;int lh=1,rh=1;
  largestBST(root,&maxi,&lh,&rh,true);
  printf(" Size of the largest BST is %d", maxi);
 
  getchar();
  return 0;
}