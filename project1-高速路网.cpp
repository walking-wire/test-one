#include "state.h"
#include<string.h>
#include <cstdlib>
#define min(a, b) (((a) < (b)) ? (a) : (b))
int d[2][50000]; //从源点到其他点的最短路 
struct State *s;//s是州起点
//把点权作为边权 
struct edge {
	int val;//边的起点 
    int des;
	int next;//边的终点 
	int weight;//边权
}e[3000000];//不够再加---表示边

int eid = 0;
int p[5000];//p用于邻接表的头结点
int vis[5000], q[500000];//q是队列，vis用于SPFA中
int minlen = 0 , r , l;//r,l表示队列左右
int mark = 0;//mark就是六边形总数 也即最后一个六边形的编号 
int W[5010];//每个标号对应权重 
int slen, dlen, slines, dlines;//s-single奇数行数slen，奇数行所含六边形个数slines，d-double偶数行数dlen，偶数行所含六边形个数dlines 
int row;//行总数 

void print()
{
    for(int i=1;i<=mark;i++)
    {
        printf("%d: ",i);
        for(int j=p[i];j!=-1;j = e[j].next)
        {
            printf("%d--%d--%d   ",e[j].val,e[j].des,e[j].weight);
        }
        printf("\n");
    }
}

void insert(int mark1, int mark2, int w)//w传的是mark2的点权 
{
	e[eid].val = mark2;
    e[eid].des = mark1;
	e[eid].next = p[mark1];
	e[eid].weight = w;
	p[mark1] = eid++;
}

void insert2(int mark1, int mark2, int w1, int w2)//w1是mark2->mark1的边权，w2是mark1->mark2的边权
{
	insert(mark1, mark2, w1);
	insert(mark2, mark1, w2);
}

void debug()
{
    printf("mark = %d ", mark);
    for(int i = 1; i<= mark; i++)
    {
        printf("\n%d: ", i);
        for(int j = p[i]; ~j; j = e[j].next)
        {
            printf("%d ", e[j].val);
        }
    }
}

void init_State(struct State *s) {

    memset(p, -1, sizeof(p));//初始化邻接表的头节点
    s->dot = 1;
    s->weight = 0;//起点州权重不用算入结果，故置为0
    return;
}
void delete_State(struct State *s) {
    //free(s);
    s = NULL;
    return;
}
void parse(struct State *s, struct PNG *p) {

    s->dot = 1;
    s->weight = 0;
    row = 1;//行总数
    slines = dlines = slen = dlen = 0;
    for(int i = 6; i< p->height; i += 8)
	{
		if(row % 2 == 1)//若从长行开始，则奇数行为长行 
		{
			slines++;//奇数行个数 
			for(int j = 4; j< p->width; j += 8)
			{
				mark++;
				struct PXL* temp = get_PXL(p, j, 6 + 8*2*(slines - 1));//获取j行6列的像素色块
				W[mark] = 255*255*3 - temp->red * temp->red - temp->green * temp->green - temp->blue * temp->blue;//算RGB   
				if(i == 6)
				{
					slen++;//一个奇数行含的六边形个数 
				}
			}
		}
		else//偶数行为短行
		{
			dlines++;//偶数行个数 
			for(int j = 8; j<= p->width; j += 8)
			{
				mark++;
				struct PXL* temp = get_PXL(p, j, 6+ 8*(1 + 2*(dlines - 1)));//获取j行14列的像素色块
				W[mark] = 255*255*3 - temp->red * temp->red - temp->green * temp->green - temp->blue * temp->blue;//算RGB 
				if(W[mark] == 0)//如果取到的是白色，则回退 
				{
					mark--;
				}
			}
		}
        dlen = slen - 1;//一个偶数行含的六边形个数 
		row++;
	}
    	/*边的连接*/
	for (int i = 1; i <= slines; i++)//奇数行边的连接
	{
		for (int j = (slen + dlen) * (i - 1) + 1; j < (slen + dlen) * (i - 1) + 1 + slen; j++)
		{
			if (j + slen <= mark && j!=(slen+dlen)*(i-1)+slen)
			{
				insert2(j, j + slen, W[j + slen], W[j]);
			}
			if (j + 1 < i * slen + (i - 1) * dlen + 1)
			{
				insert2(j, j + 1, W[j + 1], W[j]);
			}
		}
		for (int j = i * slen + (i - 1) * dlen; j > (slen + dlen) * (i - 1) + 1; j--)
		{
			if (j + dlen <= mark)
			{
				insert2(j, j + dlen, W[j + dlen], W[j]);
			}
		}
	}

	for (int i = 1; i <= dlines; i++)
	{
		for (int j = i * slen + (i - 1) * dlen + 1; j <= i * (slen + dlen); j++)
		{
			if (j == i * (slen + dlen) && j != mark)
			{
				insert2(j, j + dlen, W[j + dlen], W[j]);
				insert2(j, j + slen, W[j + slen], W[j]);
				continue;
			}
			if (j >= mark)
			{
				break;
			}
			if (j + dlen <= mark)
			{
				insert2(j, j + dlen, W[j + dlen], W[j]);
			}
			if (j + slen <= mark)
			{
				insert2(j, j + slen, W[j + slen], W[j]);
			}
			if (j + 1 <= i * (slen + dlen))
			{
				insert2(j, j + 1, W[j + 1], W[j]);
			}
		}
	}

    //debug();
    //print();
}

int solve1(struct State *s) {
	memset(vis, 0, sizeof(vis));//初始化 
	int start = 0;
	if(s->dot == 1) {
        memset(d, 0x3f, sizeof(d));
		start = 0;//起点 
	} else {
		start = 1;//终点 
	}
    d[start][s->dot] = 0;
    vis[s->dot] = 1;
    q[r++] = s->dot;
    
    while (l != r) {
        int now = q[l++];
        vis[now] = 0;
        for (int i = p[now]; i != -1; i = e[i].next) {
            int v = e[i].val;
            if (d[start][v] > d[start][now] + e[i].weight) {
                d[start][v] = d[start][now] + e[i].weight;
                if (!vis[v]) {
                    q[r++] = v;
                    vis[v] = 1;
                }
            }
        }
    } 
    if(s->dot == 1) {
    	minlen = d[start][mark];//最短路 
	}
    /*
    printf("mark = %d * minlen = %d\n",mark,minlen);
    for(int i=1;i<=mark;i++)
    {
        printf("d[%d] = %d\n",i,d[start][i]);
    }
    printf("\n");
    */
	return minlen; 
}
int solve2(struct State *s) {
    
	int shortest;//最短路 
	s->dot = 1;
    s->weight = 0;
    //printf("1\n");
	shortest = solve1(s);//有待修改  ， 起点到其他点最短路
    s->dot = mark;
	s->weight = W[mark];
    //printf("*%d*\n",W[mark]);
    //printf("mark = %d\n",mark);
	solve1(s);//此处n代表终点标号，有待修改 ，终点到其他点最短路 
	
	int cnt = 0x3f3f3f3f;//次短路 
	
	for (int i = 0 ; i < eid ; i++) {//此处可以剪枝 
		int u = e[i].val;
		int v = e[i].des;
		//int w = e[i].weight;
		
		if (d[0][u] + d[1][v] + W[mark] > shortest) {
			cnt = min(cnt, d[0][u] + d[1][v] + W[mark]);
		}
        //printf("(%d , %d) W[mark] = %d d[0] = %d d[1] = %d cnt = %d\n",u,v,W[mark],d[0][u],d[1][v],cnt);
	} 
	return cnt;
}

