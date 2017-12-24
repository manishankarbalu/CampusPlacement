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

    void rightSideViewUtil(TreeNode* root,vector<int> &v,int* maxLevel,int level)
    {
        if(!root)
           return;
        if(*maxLevel<level)
        {
            *maxLevel=level;
            v.push_back(root->val);
        }
        
        rightSideViewUtil(root->right,v,maxLevel,level+1);
        rightSideViewUtil(root->left,v,maxLevel,level+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> v;
        int level=1,maxLevel=0;
        rightSideViewUtil(root,v,&maxLevel,level);
        return v;
    }
};