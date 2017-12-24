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
    bool isSymmetricUtil(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL)
          return true;
        if(p && q)
          { return ((p->val == q->val) && isSymmetricUtil(p->left,q->right) && isSymmetricUtil(p->right,q->left));
          }
        return false;
        
    }
   
    bool isSymmetric(TreeNode* root) {
        if(!root)
         return true;
        
        return isSymmetricUtil(root,root);
        
    }
};