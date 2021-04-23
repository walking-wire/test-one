
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};


int Size(struct TreeNode* root)
{
    if(!root)   return 0;
    return Size(root->left)+Size(root->right)+1;
}

void PreOrder(struct TreeNode* root, int* ret, int* size)
{
    if(!root)   return;
    ret[(*size)++] = root->val;
    PreOrder(root->left, ret, size);
    PreOrder(root->right, ret, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ret = (int*)malloc(sizeof(int) * Size(root));
    *returnSize = 0;
    PreOrder(root, ret, returnSize);
    return ret;
}
