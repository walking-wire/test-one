#include"sanziqi.h"
/*C����ʵ��������*/

int main()
{
	int k = 0;
	char board[ROW][COL] = {0};
	Beginning();
	printf("��ѡ���Ƿ�ʼ��Ϸ(����1��ʾ������Ϸ������0��ʾ�˳���Ϸ)��");
	while(1)
	{
		scanf("%d",&k);
		if(k == 1)
		{
			break;
		}
		else if(k == 0)
		{
			return 0;
		}
		else
		{
			printf("�������֣����������루1����0��:"); 
		}
	}
	Initialboard(board,ROW,COL);
	Createboard(board,ROW,COL);//��ʾ����
	while(1)
	{
		Playerturn(board,ROW,COL);//��Ϸ������
		Createboard(board,ROW,COL);//��ʾ����
		Iswin(board,ROW,COL);//�ж��Ƿ������ʤ�����
		if(Iswin(board,ROW,COL) == '*')
		{
			printf("���ʤ��");break;
		}
		else if (Iswin(board,ROW,COL) == '#')
		{
			printf("�����ʤ��");break;
		}
		else if (Iswin(board,ROW,COL) == 'T')
		{
			printf("ƽ��");break;
		}
		Computerturn(board,ROW,COL);//���������
		Createboard(board,ROW,COL);//��ʾ����
		Iswin(board,ROW,COL);//�ж��Ƿ������ʤ�����
		if(Iswin(board,ROW,COL) == '*')
		{
			printf("���ʤ��");break;
		}
		else if (Iswin(board,ROW,COL) == '#')
		{
			printf("�����ʤ��");break;
		}
		else if (Iswin(board,ROW,COL) == 'T')
		{
			printf("ƽ��");break;
		}
	}
	return 0;
}
