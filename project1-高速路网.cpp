#include "state.h"
#include<string.h>
#include <cstdlib>
#define min(a, b) (((a) < (b)) ? (a) : (b))
int d[2][50000]; //��Դ�㵽����������· 
struct State *s;//s�������
//�ѵ�Ȩ��Ϊ��Ȩ 
struct edge {
	int val;//�ߵ���� 
    int des;
	int next;//�ߵ��յ� 
	int weight;//��Ȩ
}e[3000000];//�����ټ�---��ʾ��

int eid = 0;
int p[5000];//p�����ڽӱ��ͷ���
int vis[5000], q[500000];//q�Ƕ��У�vis����SPFA��
int minlen = 0 , r , l;//r,l��ʾ��������
int mark = 0;//mark�������������� Ҳ�����һ�������εı�� 
int W[5010];//ÿ����Ŷ�ӦȨ�� 
int slen, dlen, slines, dlines;//s-single��������slen�����������������θ���slines��d-doubleż������dlen��ż�������������θ���dlines 
int row;//������ 

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

void insert(int mark1, int mark2, int w)//w������mark2�ĵ�Ȩ 
{
	e[eid].val = mark2;
    e[eid].des = mark1;
	e[eid].next = p[mark1];
	e[eid].weight = w;
	p[mark1] = eid++;
}

void insert2(int mark1, int mark2, int w1, int w2)//w1��mark2->mark1�ı�Ȩ��w2��mark1->mark2�ı�Ȩ
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

    memset(p, -1, sizeof(p));//��ʼ���ڽӱ��ͷ�ڵ�
    s->dot = 1;
    s->weight = 0;//�����Ȩ�ز���������������Ϊ0
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
    row = 1;//������
    slines = dlines = slen = dlen = 0;
    for(int i = 6; i< p->height; i += 8)
	{
		if(row % 2 == 1)//���ӳ��п�ʼ����������Ϊ���� 
		{
			slines++;//�����и��� 
			for(int j = 4; j< p->width; j += 8)
			{
				mark++;
				struct PXL* temp = get_PXL(p, j, 6 + 8*2*(slines - 1));//��ȡj��6�е�����ɫ��
				W[mark] = 255*255*3 - temp->red * temp->red - temp->green * temp->green - temp->blue * temp->blue;//��RGB   
				if(i == 6)
				{
					slen++;//һ�������к��������θ��� 
				}
			}
		}
		else//ż����Ϊ����
		{
			dlines++;//ż���и��� 
			for(int j = 8; j<= p->width; j += 8)
			{
				mark++;
				struct PXL* temp = get_PXL(p, j, 6+ 8*(1 + 2*(dlines - 1)));//��ȡj��14�е�����ɫ��
				W[mark] = 255*255*3 - temp->red * temp->red - temp->green * temp->green - temp->blue * temp->blue;//��RGB 
				if(W[mark] == 0)//���ȡ�����ǰ�ɫ������� 
				{
					mark--;
				}
			}
		}
        dlen = slen - 1;//һ��ż���к��������θ��� 
		row++;
	}
    	/*�ߵ�����*/
	for (int i = 1; i <= slines; i++)//�����бߵ�����
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
	memset(vis, 0, sizeof(vis));//��ʼ�� 
	int start = 0;
	if(s->dot == 1) {
        memset(d, 0x3f, sizeof(d));
		start = 0;//��� 
	} else {
		start = 1;//�յ� 
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
    	minlen = d[start][mark];//���· 
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
    
	int shortest;//���· 
	s->dot = 1;
    s->weight = 0;
    //printf("1\n");
	shortest = solve1(s);//�д��޸�  �� ��㵽���������·
    s->dot = mark;
	s->weight = W[mark];
    //printf("*%d*\n",W[mark]);
    //printf("mark = %d\n",mark);
	solve1(s);//�˴�n�����յ��ţ��д��޸� ���յ㵽���������· 
	
	int cnt = 0x3f3f3f3f;//�ζ�· 
	
	for (int i = 0 ; i < eid ; i++) {//�˴����Լ�֦ 
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

