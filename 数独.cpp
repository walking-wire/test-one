#include<stdio.h>
#include<string.h>
#define MAX 15
int board[MAX][MAX];
int num;

int check(int x, int y, int val)
{
    for(int i = 0; i< 9; i++)
    {
        if((board[x][i] == val && i != y) || (board[i][y] == val && i != x))
        {
            return 0;
        }
    }
    int x1 = x / 3;
    int y1 = y / 3;
    for(int i = x1 * 3; i < x1 * 3 + 3; i++)
    {
        for(int j = y1 * 3; j < y1 * 3 + 3; j++)
        {
            if(board[i][j] == val && i != x && j != y)  return 0;
        }
    }
    return 1;
}

int DFS(int num)
{
    if(num >= 81)   return 1;
    int x = num / 9;
    int y = num % 9;
    if(board[x][y] == 0)
    {
            for(int p = 1; p <= 9; p++)
            {
                board[x][y] = p;
                if(check(x, y, p) == 1)
                {
                    if(DFS(num + 1)) return 1;
                }
                board[x][y] = 0;//如果不行就回溯找下一个p
            }
    }
    else return DFS(num + 1);
    return 0;
}

void Print()
{
    for(int i = 0; i< 9; i++)
    {
        for(int j = 0; j< 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    num = 0;
    char tmp;
    memset(board, 0, sizeof(board));
    for(int i = 0; i< 9; i++)
    {
        for(int j = 0; j< 9; j++)
        {
            scanf("%c ", &tmp);
            if(tmp == '*')
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = tmp - '0';
            }
        }
    }
    DFS(0);
    Print();
    return 0;
}
