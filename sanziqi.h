#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
/*������Ϸ�˵���*/ 
void Beginning()
{
	printf("***************************\n");
	printf("***** 1.enter  0.exit *****\n");
	printf("***************************\n");
}
/*��ʼ������*/
void Initialboard(char board[ROW][COL], int row, int col)
{
	int i = 0,j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j] = ' ';
		}
	}
} 
/*��ʾ����*/
void Createboard(char board[ROW][COL], int row, int col)
{
	int i = 0,j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			printf("|");
		}
		printf("\n");
		for(j=0;j<col;j++)
		{
				printf("---");
				if(j<col-1)
				{
					printf("|");
				}
		}
		printf("\n");
	}
}
/*��Ϸ������*/
void Playerturn(char board[ROW][COL], int row, int col)
{
	int x= 0 , y = 0;
	printf("�ֵ�������:>\n");
	while(1)
	{
		printf("��������Ҫ�����ӵ�����:");
		scanf("%d %d",&x,&y);
		if(x>=1 && x<=row && y>=1 && y<=col &&board[x-1][y-1]==' ')
		{
			board[x-1][y-1] = '*';break;
		}
		else
		{
			printf("�����������������");
		}
	}
}
/*��������*/
void Computerturn(char board[ROW][COL], int row, int col)
{
	srand((unsigned)time(NULL));//�����������Ϊ�������������׼�� 
	int x = 0,y = 0;
	printf("�ֵ����������:>\n");
	printf("������������\n");
	while(1)
	{
		x = rand()%3;
		y = rand()%3;
		if(board[x][y] == ' ')
		{
			board[x][y] = '#';break;
		}
	}
}
/*�ж��Ƿ����,ʤ�����*/
//'*'Ϊ��Ϸ��ʤ
//'#'Ϊ����ʤ
//'T'Ϊƽ��
//'G'Ϊ����
char Isfull(char board[ROW][COL], int row, int col)
{
	int i= 0, j = 0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for(i=0;i<ROW;i++)//��ʤ�� 
	{
		if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][1]!=' '))
		{
			return board[i][1];
		}
	}
	for(i=0;i<COL;i++)//��ʤ��
	{
		if((board[0][i]==board[1][i]) && (board[1][i]==board[2][i]) && (board[1][i]!=' '))
		{
			return board[1][i];
		}
	} 
	if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && (board[1][1]!=' '))//бʤ�� 
	{
		return board[1][1];
	}
	if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && (board[1][1]!=' '))//бʤ�� 
	{
		return board[1][1];
	}
	if(Isfull(board,ROW,COL) == 0)
	{
		return 'G';
	}
	if(Isfull(board,ROW,COL) == 1)
	{
		return 'T';
	}
}
