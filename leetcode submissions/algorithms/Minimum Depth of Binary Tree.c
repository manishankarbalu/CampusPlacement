/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void minDepthUtil(struct TreeNode* root,int *min,int level)
{
    if(!root)
       return ;
    if(!root->left && !root->right)
    {
        if(*min>level)
           *min=level;
    }
    
    minDepthUtil(root->left,min,level+1);
    minDepthUtil(root->right,min,level+1);
    
}
 
int minDepth(struct TreeNode* root) {
    
    int min=INT_MAX,level=0;
    if(root)
        {minDepthUtil(root,&min,level);
        return min+1;}
    else
        return 0;
}