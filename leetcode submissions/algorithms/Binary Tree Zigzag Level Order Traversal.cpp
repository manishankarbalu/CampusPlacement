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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
       vector<vector<int>> result;
        if(!root) return result;
        
        stack<TreeNode*> curLevel;
        curLevel.push(root);
        bool forward = true; // true: print left child first then right. false: print right child first then left child
        
        while(!curLevel.empty()){
            stack<TreeNode*> nxtLevel;
            vector<int> interim;
            while(!curLevel.empty()){
                TreeNode* cur = curLevel.top();
                curLevel.pop();
                interim.push_back(cur->val);
                if(forward){
                    if(cur->left) nxtLevel.push(cur->left);
                    if(cur->right) nxtLevel.push(cur->right);
                }else{
                    if(cur->right) nxtLevel.push(cur->right);
                    if(cur->left) nxtLevel.push(cur->left);
                }
            }
            forward = !forward;
            result.push_back(interim);
            curLevel = nxtLevel;
        }
        
        return result;
    }
};