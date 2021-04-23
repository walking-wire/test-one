
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int Size(struct TreeNode *root)
{
    if(!root)   return 0;
    return Size(root->left)+Size(root->right)+1;
}

void PostOrder(struct TreeNode* root, int* ret, int* sz)
{
    if(!root)   return;
    PostOrder(root->left, ret, sz);
    PostOrder(root->right, ret, sz);
    ret[(*sz)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int n = Size(root);
    int* ret = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    PostOrder(root, ret, returnSize);
    return ret;
}
