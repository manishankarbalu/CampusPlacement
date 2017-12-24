/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(!root)
      return NULL;
      
    if(root==p || root==q)
        return root;
      
    struct TreeNode* llca=lowestCommonAncestor(root->left,p,q);
    struct TreeNode* rlca=lowestCommonAncestor(root->right,p,q);
    
    if(llca && rlca)
        return root;
    
    return (llca!=NULL)?llca:rlca;   
        
}