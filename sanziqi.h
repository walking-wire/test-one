#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
/*创建游戏菜单栏*/ 
void Beginning()
{
	printf("***************************\n");
	printf("***** 1.enter  0.exit *****\n");
	printf("***************************\n");
}
/*初始化棋盘*/
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
/*显示棋盘*/
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
/*游戏者下棋*/
void Playerturn(char board[ROW][COL], int row, int col)
{
	int x= 0 , y = 0;
	printf("轮到您下棋:>\n");
	while(1)
	{
		printf("请输入您要下棋子的坐标:");
		scanf("%d %d",&x,&y);
		if(x>=1 && x<=row && y>=1 && y<=col &&board[x-1][y-1]==' ')
		{
			board[x-1][y-1] = '*';break;
		}
		else
		{
			printf("坐标错误，请重新输入");
		}
	}
}
/*电脑下棋*/
void Computerturn(char board[ROW][COL], int row, int col)
{
	srand((unsigned)time(NULL));//生成随机数，为电脑随机下棋做准备 
	int x = 0,y = 0;
	printf("轮到计算机下棋:>\n");
	printf("计算机下棋完毕\n");
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
/*判断是否继续,胜负与否*/
//'*'为游戏者胜
//'#'为电脑胜
//'T'为平局
//'G'为继续
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
	for(i=0;i<ROW;i++)//行胜利 
	{
		if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]) && (board[i][1]!=' '))
		{
			return board[i][1];
		}
	}
	for(i=0;i<COL;i++)//列胜利
	{
		if((board[0][i]==board[1][i]) && (board[1][i]==board[2][i]) && (board[1][i]!=' '))
		{
			return board[1][i];
		}
	} 
	if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]) && (board[1][1]!=' '))//斜胜利 
	{
		return board[1][1];
	}
	if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]) && (board[1][1]!=' '))//斜胜利 
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
