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
    void findModeUtil(TreeNode* root,map<int,int> &count,int &maxi){if(!root) return;count[root->val]+=1;maxi=(maxi>count[root->val])?maxi:count[root->val];findModeUtil(root->left,count,maxi);findModeUtil(root->right,count,maxi); }vector<int> findMode(TreeNode* root) {
        map<int,int> count;vector<int> v;int maxi=INT_MIN;findModeUtil(root,count,maxi);for(auto y : count){if(y.second==maxi) v.push_back(y.first);}return v;    
        
    }
};