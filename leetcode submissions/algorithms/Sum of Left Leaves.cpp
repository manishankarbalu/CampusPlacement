/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* root,bool c)
    {
         if(!root)
             return 0;
         if(!root->left && !root->right && c)
             return root->val;
          return sum(root->left,true)+sum(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
     
         if(!root)
             return 0;
//if(!root->left && !root->right)
  //           return root->val;
          return sum(root->left,true)+sum(root->right,false);
               
        
    } 
};