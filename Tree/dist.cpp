/* Program to find distance between n1 and n2 using one traversal */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int findlevel(struct Node* root,int level,int data)
{

  if(root==NULL) return -1;

   if(root->key==data)
         return level;
    
    int l=findlevel(root->left,level+1,data);
     if(l==-1)
          return findlevel(root->right,level+1,data);
   return l;
}

struct Node* findlca(struct Node* root,int n1,int n2)
{

   if(root==NULL) return NULL;
  
if(root->key==n1 || root->key==n2)
      return root;

 struct Node* llca=findlca(root->left,n1,n2);
struct Node* rlca=findlca(root->right,n1,n2);

if(llca && rlca) return root;

return (llca!=NULL)?llca:rlca;


}

int findDistance(struct Node* root,int n1,int n2)
{
      int d1=findlevel(root,1,n1);
        int d2=findlevel(root,1,n2);

     struct Node* l=findlca(root,n1,n2);

     int d3=findlevel(root,1,l->key);
    if(d1!=-1 && d2!=-1 && d3!=-1)
    return d1+d2-2*d3;
     else return -1;
}
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5)<<endl;
    return 0;
}
