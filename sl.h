#include<stdio.h>
#include<time.h>
#include<stdlib.h>
 
#define row 9
#define col 9
#define rows 11
#define cols 11
#define MineNumbers 10

void Menu()
{
	printf("*******************\n");
	printf("*******************\n");
	printf("**1.begin  0.exit**\n");
	printf("*******************\n");
	printf("*******************\n");
}

void InitialBoard(char Board[rows][cols], int ROWS, int COLS)
{
	int i = 0;
	for(i = 0; i< ROWS; i++)
	{
		int  j = 0;
		for(j = 0; j< COLS; j++)
		{
			Board[i][j] = '0';
		}
	}
}

void InitialShowBoard(char ShowBoard[row][col], int ROW,int  COL)
{
	int i = 0;
	for(i = 0; i< ROW; i++)
	{
		int  j = 0;
		for(j = 0; j< COL; j++)
		{
			ShowBoard[i][j] = '*';
		}
	}
}
	
void DisplayShowBoard(char ShowBoard[row][col],int ROW,int COL)
{
	int i = 0;
	for(i = 0; i< ROW; i++)
	{
		int j = 0;
		for(j = 0; j< COL; j++)
		{
			printf("%c ",ShowBoard[i][j]);
			printf(" |");
		}
		printf("\n");
		for(j = 0; j< COL; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
}

char BoomSurround(char Board[rows][cols], int x,int y)
{
	char qut = '0';
	int i = x;
	for( i= x; i< x+2; i++)
	{
		int j = y;
		for( j = y; j< y+2; j++)
		{
			if(Board[i][j] == '1')
			{
				qut++;
			}
		}
	}
	return qut;
}

int IsBoom(char Board[rows][cols], int x, int y)
{
	
	if(Board[x+1][y+1] == '1')
	{
		return 0;
	}
	else
	{
		Board[x+1][y+1] = '*';
		return 1;
	}
}

int IsWin(char Board[rows][cols], int ROWS, int COLS)
{
	int i = 0;
	int k = 0;
	for( i= 1; i< ROWS-1; i++)
	{
		int j = 0;
		for( j = 1; j< COLS-1; j++)
		{
			if(Board[i][j] == '*')
			{
				k++;
			}
		}
	}
	if(k == row*col-MineNumbers)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

