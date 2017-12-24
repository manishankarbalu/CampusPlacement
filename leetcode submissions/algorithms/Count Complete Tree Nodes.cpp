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
    int lheight(TreeNode* root)
    {
        if(!root)
          return 0;
          
        return lheight(root->left)+1;
    }
    int rheight(TreeNode* root)
    {
        if(!root)
          return 0;
          
        return rheight(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        if(!root)
           return 0;
        int lh=lheight(root),rh=rheight(root);
        
        if(lh==rh) return (2<<(lh-1))-1;
        
        else
           return countNodes(root->left)+countNodes(root->right)+1;
        
    }
};