#include<stdio.h>
#include<limits.h>
#include<vector>

using namespace std;

/* A tree node structure */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 

 
/* Utility function to create a new Binary Tree node */
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
 
/* Driver function to test above functions */
int main()
{
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    
    printMaxSumPathRootToLeaf(root);
    
    getchar();
    return 0;
}