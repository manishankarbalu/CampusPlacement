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
    bool first = true;
    int prev = 0;
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        
        return (
            isValidBST(root->left)
            && check(root->val)
            && isValidBST(root->right));
    }
    
    bool check(int val)
    {
        if(first)
        {
            first = false;
            prev = val;
            return true;
        }
        
        if(prev >= val) return false;
        
        prev = val;
        return true;
    }
};