#iostream

BTNode* FindNode(BTNode *b, x)
{
	BTNode* p;
	if(!b)
	{
		return NULL;
	}
	if(b->data == x)
	{
		return b;
	}
	p = FindNode(b->lchild,x);
	if(p)
	{
		return p;
	}
	else
	{
		return FindNode(b->rchild,x);
	}
}
