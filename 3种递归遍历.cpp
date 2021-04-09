#iostream

void PreOrder(BT *p)//Ç°Ðò 
{
	if(!p)
	{
		printf("%d",p->val);
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

void InOrder(BT * p)//ÖÐÐò 
{
	if(!p)
	{
		Inorder(p->left);
		printf("%d",p->val);
		Inorder(p->right);
	}
}

void PostOrder(BT * p)//ºóÐò 
{
	if(!p)
	{
		PostOrder(p->left);
		PostOrder(p->right);
		printf("%d",p->val);
	}
}
