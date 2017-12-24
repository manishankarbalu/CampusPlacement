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
    void hasSum(TreeNode* root,int cursum,int sum,vector<int> &p,vector<vector<int>> &P)
    {
        if(!root)
            return;
        cursum+=root->val;
        p.push_back(root->val);
        if(!root->left && !root->right && cursum==sum)
              P.push_back(p);
        hasSum(root->left,cursum,sum,p,P);
        hasSum(root->right,cursum,sum,p,P);
        p.pop_back();
            
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> P;
        vector<int> p;
        hasSum(root,0,sum,p,P);
        return P;        
    }
};