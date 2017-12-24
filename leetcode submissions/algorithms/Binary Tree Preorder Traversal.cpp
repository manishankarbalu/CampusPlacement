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
    void preorderTraversalUtil(TreeNode* root,vector<int> &v)
    {
        if(!root)
           return;
        v.push_back(root->val);
        preorderTraversalUtil(root->left,v);
        preorderTraversalUtil(root->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> v;
        
        preorderTraversalUtil(root,v);
        
        return v;
    }
};