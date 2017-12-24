/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int max(int a ,int b)
 {
     return (a>b)?a:b;
 }
 
int diameterOfBinaryTreeUtil(struct TreeNode* root,int* height)
{
    
    int lh=0,rh=0,ld=0,rd=0;
    if(!root)
    {
        *height=0;
        return 0;
    }
    
    ld=diameterOfBinaryTreeUtil(root->left,&lh);
    rd=diameterOfBinaryTreeUtil(root->right,&rh);
    
    *height=(lh>rh)?lh+1:rh+1;
    
    return max(lh+rh,max(ld,rd));
    
    
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int height=0;
    return diameterOfBinaryTreeUtil(root,&height);
    
}