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

    void binaryTreePathsUtil(TreeNode* root,vector<string> &v,string s)
    {
        
        if(!root->left && !root->right)
        {
            v.push_back(s);
            return;
        }
        
        if(root->left)
        binaryTreePathsUtil(root->left,v,s+"->"+to_string(root->left->val));
        if(root->right)
        binaryTreePathsUtil(root->right,v,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> v;
        string s;
        if(root)
           binaryTreePathsUtil(root,v,to_string(root->val));
        return v;
        
    }
};