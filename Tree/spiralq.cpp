// C++ implementation of a O(n) time method for spiral order traversal
#include <iostream>
#include <stack>
using namespace std;
 
// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};
 
void printSpiral(struct node *root)
{
      if(root==NULL) return;
     stack<struct node*>s1;
     stack<struct node*>s2;
    s2.push(root);
         while(!s1.empty() || !s2.empty())
         {
                 while(!s1.empty())
                 {
                      struct node* ptr=s1.top();
                   cout<<ptr->data<<" ";
                      s1.pop();
                   if(ptr->left)
                    s2.push(ptr->left);
                    if(ptr->right)   
                  s2.push(ptr->right);
                 }
                 while(!s2.empty())
                 {
                    struct node* ptr=s2.top();
                   cout<<ptr->data<<" ";
                        s2.pop();
                       if(ptr->right)
                    s1.push(ptr->right);
                        if(ptr->left)
                     s1.push(ptr->left);
                 }

         }

}
 
// A utility function to create a new node
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiral(root);
 
    return 0;
}

