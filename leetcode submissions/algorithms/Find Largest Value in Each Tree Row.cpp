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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> v;
        if(!root)
           return v;
        q.push(root);
        int nodeCount=0;
        while(1)
        {
            nodeCount=q.size();
            int maxValue=INT_MIN;
            if(nodeCount==0)
               break;
            
            while(nodeCount>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(maxValue<temp->val)
                   maxValue=temp->val;
                   
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                    
                nodeCount--;
            }
            v.push_back(maxValue);
        }
        
        return v;
    }
};