#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left, *right;
};
/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 
/* function to create a new node of tree and returns pointer */
struct node* newNode(int data);
 int findDiameter(struct node* root,int *height)
{
	int lh=0,rh=0,ld=0,rd=0;
	if(!root)
		{
			*height=0;
			return 0;	
	    }
	ld=findDiameter(root->left,&lh);
	rd=findDiameter(root->right,&rh);

	*height=(lh>rh)?lh+1:rh+1;

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
 printf("%d",findDiameter(root,&height));
 
  getchar();
  return 0;
}
/*
// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std; 
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void printLeftView(struct node* root,int level,int* maxlevel,vector<int> &v)
{
   if(!root)
   	return;
   if(*maxlevel<level)
   {
    v.push_back(root->data);
   	*maxlevel=level;
   }
   printLeftView(root->left,level+1,maxlevel,v);
   printLeftView(root->right,level+1,maxlevel,v);
}

void leftView(struct node* root)
{
	vector<int> v;
	int level=1,maxlevel=0;
	printLeftView(root,level,&maxlevel,v);

       for(int i=0;i<v.size();i++)
    	   printf("%d ",v[i]);
printf("\n");
}

 
// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    leftView(root);
 return 1;
}   
*/
/*
    #include <stdio.h>
    #include <stdlib.h>
    #include<vector>
    using namespace std;
     
    
    struct node
    {
        int data;
        struct node *left, *right;
    };
     

    void leftTraversal(struct node* root,vector<int>& v)
    {
        if(!root)
        	return;
    
    if(root->left)
      {
        v.push_back(root->data);
        leftTraversal(root->left,v);
      }
    else
        if(root->right)
        { 
         v.push_back(root->data);
         leftTraversal(root->right,v);

        }
    }
     
    void rightTraversal(struct node* root,vector<int>& v)
    {
    if(!root)
        	return;
       
    if(root->right)
      {
        v.push_back(root->data);
        leftTraversal(root->right,v);
      }
    else
        if(root->left)
        { 
         v.push_back(root->data);
         leftTraversal(root->left,v);

        }
    }
     
    void leafTraversal(struct node* root,vector<int>& v)
    {
     
         if(!root)
         	return;
         if(root->left==NULL && root->right==NULL)
         	v.push_back(root->data);
         leafTraversal(root->left,v);
         leafTraversal(root->right,v);
    }
     
    void boundaryTraversal(struct node* root)
    {
    	if(!root)
    		return;
    	vector<int> v;
        v.push_back(root->data);
    	leftTraversal(root->left,v);   	
        leafTraversal(root,v);
        rightTraversal(root->right,v);
    	
    	for(int i=0;i<v.size();i++)
    	   printf("%d ",v[i]);
    }
     
 
    
    struct node* newNode( int data )
    {
        struct node* temp = (struct node *) malloc( sizeof(struct node) );
     
        temp->data = data;
        temp->left = temp->right = NULL;
     
        return temp;
    }
     
    // Driver program to test above functions
    int main()
    {
        // Let us construct the tree given in the above diagram
        struct node *root         = newNode(20);
        root->left                = newNode(8);
        root->left->left          = newNode(4);
        root->left->right         = newNode(12);
        root->left->right->left   = newNode(10);
        root->left->right->right  = newNode(14);
        root->right               = newNode(22);
        root->right->right        = newNode(25);
     
        boundaryTraversal( root );
     
        return 0;
    }
*/
/*
#include<stdio.h>
#include<limits.h>
#include<vector>

using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 

 

struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
bool printPathWithMaxSum(struct node* root,int curSum,int maxSum,vector<int> &v)
{
	if(!root)
		return false;
	curSum+=root->data;

	if(curSum==maxSum || printPathWithMaxSum(root->left,curSum,maxSum,v) || printPathWithMaxSum(root->right,curSum,maxSum,v))
    {
    	v.push_back(root->data);
    	return true;
    }
  return false;
}
void findMaxSum(struct node* root,int curSum,int *maxSum)
{
	if(!root)
		return;
	curSum+=root->data;
	if(!root->left && !root->right)
	{
		if(*maxSum<curSum)
			*maxSum=curSum;
	}
	findMaxSum(root->left,curSum,maxSum);
	findMaxSum(root->right,curSum,maxSum);
}

void printMaxSumPathRootToLeaf(struct node* root)
{
	int maxSum=INT_MIN;
    int curSum=0;
	findMaxSum(root,curSum,&maxSum);
	printf("%d\n",maxSum);
	vector<int> v;
	printPathWithMaxSum(root,curSum,maxSum,v);
	for(int i=v.size()-1;i>=0;i--)
	 printf("%d  ",v[i]);
}
 

int main()
{
    struct node *root = NULL;
 
   
    root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    
    printMaxSumPathRootToLeaf(root);
    
    getchar();
    return 0;
}
*/
/*

#include<stdio.h>
#include<stdlib.h>
#include<vector>
  

using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
void printVectorPaths(vector<int> v,int ptr)
{
         for(int i=0;i<ptr;i++)
         	printf("%d ",v[i]);
           printf("\n");
}

void printPaths(struct node* root,vector<int> v,int ptr)
{
   if(root==NULL)
   	 return;

   v.push_back(root->data);
   	ptr++;

   	if(root->left==NULL && root->right==NULL)
   		printVectorPaths(v,ptr);
   
   	printPaths(root->left,v,ptr);
   	printPaths(root->right,v,ptr);


}

void printRootToLeafPaths(struct node* root)
{
	vector<int> v;int ptr=0;
	printPaths(root,v,ptr);
}

 
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}
  

int main()
{ 
  
  
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(21);
  
  printRootToLeafPaths(root);
  
  getchar();
  return 0;
}*/
