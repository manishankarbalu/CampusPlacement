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
      void inorderTraversalUtil(TreeNode* root,vector<int> &v)
      {
         if(!root)
           return;
    
            inorderTraversalUtil(root->left,v);
            v.push_back(root->val);
             inorderTraversalUtil(root->right,v);
      }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        inorderTraversalUtil(root,v);
        return v;
    }
};