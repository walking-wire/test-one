#include"sl.h"

/*ɨ��*/

int main()
{
	do{
		Menu();
		int number = 0;
		scanf("%d",&number);
		if(number == 1)
		{
			break;
		}
		else if(number == 0)
		{
			return 0;
		}
		else
		{
			printf("�����������������\n");
		}
	}while(1);
	char Board[rows][cols] = { 0 };
	char ShowBoard[row][col] = { 0 };
	InitialBoard(Board, rows, cols);
	InitialShowBoard(ShowBoard, row, col);
	DisplayShowBoard(ShowBoard, row, col);
	int k = 0;
	for(k = 0; k< MineNumbers; k++)
	{
		int H = 0;
		int Z = 0;
		srand((int)time(0));
		H = rand()%9+1;
		Z = rand()%9+1;
		Board[H][Z] = '1';
	}
	int ret = 1;
	while(ret)
	{
		printf("���������ĺ�����:>\n");
		int x = 0;
		int y = 0;
		scanf("%d",&x);
		printf("����������������:>\n");
		scanf("%d",&y);
		IsBoom(Board, x, y);
		ShowBoard[x][y] = BoomSurround(Board, x, y);
		DisplayShowBoard(ShowBoard, row, col);
		if(IsWin(Board, rows, cols) == 1)
		{
			printf("Congratulations!\n");
			return 0;
		}
	}
	printf("GAME OVER\n");
	return 0;
}
		
