

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}; 


int Size(struct TreeNode* root)
{
    if(!root)   return 0;
    return Size(root->left)+Size(root->right)+1;
}

void MidTraversal(struct TreeNode* root, int* ret, int* size)
{
    if(!root)   return;
    MidTraversal(root->left, ret, size);
    ret[(*size)++] = root->val;
    MidTraversal(root->right, ret, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(!root)   
    {
    *returnSize = 0;
    return NULL;
    }
    int n = Size(root);
    int* ret = (int*)malloc(sizeof(int) * n);
    memset(ret,0,n);
    *returnSize = 0;
    MidTraversal(root, ret, returnSize);
    return ret;
}
