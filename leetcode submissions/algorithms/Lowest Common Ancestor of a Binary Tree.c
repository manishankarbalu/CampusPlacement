/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* lowestCommonAncestorUtil(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q,int* v1,int* v2)
 {
 if(!root)
      return NULL;
      
    if(root==p)
    {
        *v1=1;
        return root;
    }
    if(root==q)
    {
        *v2=1;
        return root;
    }  
    struct TreeNode* llca=lowestCommonAncestorUtil(root->left,p,q,v1,v2);
    struct TreeNode* rlca=lowestCommonAncestorUtil(root->right,p,q,v1,v2);
    
    if(llca && rlca)
        return root;
    
    return (llca!=NULL)?llca:rlca;   
 }
 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int v1=0,v2=0;
    struct TreeNode* lca=lowestCommonAncestorUtil(root, p, q, &v1, &v2);
    return lca;
    
}