#include"sanziqi.h"
/*C语言实现三字棋*/

int main()
{
	int k = 0;
	char board[ROW][COL] = {0};
	Beginning();
	printf("请选择是否开始游戏(输入1表示进入游戏，输入0表示退出游戏)：");
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
			printf("错误数字，请重新输入（1或者0）:"); 
		}
	}
	Initialboard(board,ROW,COL);
	Createboard(board,ROW,COL);//显示棋盘
	while(1)
	{
		Playerturn(board,ROW,COL);//游戏者下棋
		Createboard(board,ROW,COL);//显示棋盘
		Iswin(board,ROW,COL);//判断是否继续，胜负与否
		if(Iswin(board,ROW,COL) == '*')
		{
			printf("玩家胜利");break;
		}
		else if (Iswin(board,ROW,COL) == '#')
		{
			printf("计算机胜利");break;
		}
		else if (Iswin(board,ROW,COL) == 'T')
		{
			printf("平局");break;
		}
		Computerturn(board,ROW,COL);//计算机下棋
		Createboard(board,ROW,COL);//显示棋盘
		Iswin(board,ROW,COL);//判断是否继续，胜负与否
		if(Iswin(board,ROW,COL) == '*')
		{
			printf("玩家胜利");break;
		}
		else if (Iswin(board,ROW,COL) == '#')
		{
			printf("计算机胜利");break;
		}
		else if (Iswin(board,ROW,COL) == 'T')
		{
			printf("平局");break;
		}
	}
	return 0;
}
