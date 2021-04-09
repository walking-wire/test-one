#iostream

void DestroyTree(BTNode * &b)
{
	if(!b)
	{
		DestroyTree(b->lchild);
		DestroyTree(b->rchild);
		free(b);
	}
}
