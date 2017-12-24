#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
/* A tree node structure */
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
 
/* The functions prints all the keys which in the given range [k1..k2].
    The function assumes than k1 < k2 */
void Print(struct node *root, int k1, int k2, vector<int> &v)
{
  if(!root)
  	return;
/*  if(root->data==k1 || root->data==k2)
  {
  	v.push_back(root->data);return;
  }*/
  if(k1<root->data)
    Print(root->left,k1,k2,v);
  if(root->data>=k1 && root->data<=k2)
    {
    	v.push_back(root->data);
    	//return;
    }
  if(k2>root->data)
    Print(root->right,k1,k2,v);
 // cout<<root->data<<' ';
}
 
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
  struct node *temp = new struct node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
 
  return temp;
}
 
/* Driver function to test above functions */
int main()
{
  struct node *root = new struct node;
  int k1 = 10, k2 = 25;
 
  /* Constructing tree given in the above figure */
  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->right->right= newNode(25);
  root->right->right->right = newNode(26);
 vector<int> v;
  Print(root, k1, k2,v);
 cout<<endl<<"matter";
 for(int i: v)
   cout<<i<<' ';
  getchar();
  return 0;
}