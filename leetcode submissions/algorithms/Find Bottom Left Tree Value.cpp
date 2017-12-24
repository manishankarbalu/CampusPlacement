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

    void findBottomLeftValueUtil(TreeNode* root,int *n,int level,int* maxlevel)
    {
        if(!root)
           return;
           
        if(*maxlevel<level)
        {
            *maxlevel=level;
            *n=root->val;
        }
        
        findBottomLeftValueUtil(root->left,n,level+1,maxlevel);
        findBottomLeftValueUtil(root->right,n,level+1,maxlevel);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int n=0,level=1,maxlevel=INT_MIN;
        findBottomLeftValueUtil(root,&n,level,&maxlevel);
        return n;
    }
};