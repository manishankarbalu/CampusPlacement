// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>
 
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
 
// Recursive function to print left view of a binary tree.
void rightViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for left and right subtrees
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}
 
// A wrapper over leftViewUtil()
void rightView(struct node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
 
// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(30);
    root->right = newNode(10);
    root->left->left = newNode(25);
    root->left->right = newNode(40);
    root->left->right->right=newNode(60);
    rightView(root);
 
    return 0;
}