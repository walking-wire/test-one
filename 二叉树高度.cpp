#iostream

int maxDepth(struct TreeNode* root)
{
    int LeftDepth;
    int RightDepth;
    if(!root)
    {
        return 0;
    }
    LeftDepth = maxDepth(root->left);
    RightDepth = maxDepth(root->right);
    return (LeftDepth > RightDepth)?(LeftDepth + 1):(RightDepth + 1);
}
