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
    int hasSum(TreeNode* root,int cursum,int sum)
    {
        if(!root)
            return 0;
        cursum+=root->val;
        if(!root->left && !root->right && cursum==sum)
            return 1;
        return hasSum(root->left,cursum,sum)||hasSum(root->right,cursum,sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return hasSum(root,0,sum);
        
    }
};