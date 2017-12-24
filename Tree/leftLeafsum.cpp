// A C++ program to find sum of all left leaves
#include <iostream>
using namespace std;

/* A binary tree Node has key, pointer to left and right
children */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointer. */
Node *newNode(char k)
{
	Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

bool isLeaf(struct Node* node)
{
	if(node==NULL) return false;
	if(node->left==NULL && node->right==NULL) return true;
	
	return false;
}
int leftLeavesSumUtil(struct Node* root,bool b)
{        
     if(root==NULL) return 0;
   int sum=0;	
     if(isLeaf(root) && b ) sum+=root->key;
	else
      {  sum+=leftLeavesSumUtil(root->left,true);
	
        sum+=leftLeavesSumUtil(root->right,false);
	}return sum;
}
int leftLeavesSum(struct Node* root)
{
	 if(root==NULL) return 0;
	// if(isLeaf(root)) return root->key;
	 //int sum=0;
	int res=leftLeavesSumUtil(root->left,true)+leftLeavesSumUtil(root->right,false);
  return res;
}

/* Driver program to test above functions*/
int main()
{
	// Let us construct the Binary Tree shown in the
	// above figure
	struct Node *root		 = newNode(20);
	root->left			 = newNode(9);
	root->right			 = newNode(49);
	root->right->left		 = newNode(23);
	root->right->right	 = newNode(52);
	root->right->right->left = newNode(50);
	root->left->left		 = newNode(5);
	root->left->right		 = newNode(12);
	root->left->right->right = newNode(12);
	cout << "Sum of left leaves is "
		<< leftLeavesSum(root);
	return 0;
}

