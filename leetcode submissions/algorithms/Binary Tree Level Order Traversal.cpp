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
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        queue<TreeNode*> q;
        vector<vector<int>> V;
        if(!root)
           return V;
        q.push(root);
        int nodeCount=0;
        while(1)
        {
            nodeCount=q.size();
            vector<int> v;
            if(nodeCount==0)
               break;
            
            while(nodeCount>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                   
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                    
                nodeCount--;
            }
            V.push_back(v);
        }
      return V;  
    }
};