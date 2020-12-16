#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*ð�����������*/

void swap(char * a , char * b, int width)
{
	int i = 0;
	for(i = 0; i< width; i++)
	{
		int tmp = 0;
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

int cmp(const void* e1, const void* e2)
{
	if(*(int*)(e1) - (*(int*)(e2)) > 0)
	{
		return 1;
	}
	else if (*(int*)(e1) - (*(int*)(e2)) == 0)//����int�������� ���Խ���ߵ�if���θ�Ϊreturn (int)(*(int)e1 - *(int)e2) 
	{
		return 0;
	}
	else if (*(int*)(e1) - (*(int*)(e2)) < 0)
	{
		return -1;
	}
}

void Bubble_sort(void * arr, int sz,int width, int (*p)(const void* e1, const void* e2))
{
	int i = 0;
	for(i = 0; i< sz-1; i++)
	{
		int j = 0;
		int flag = 1;
		for(j = 0; j< sz-i-1; j++)
		{
			if(cmp((char*)arr+j*width, (char*)arr+(j+1)*width) > 0)
			{
				swap((char*)arr+j*width, (char*)arr+(j+1)*width, width);
				flag = 0;
			}
		}
		if(flag == 1)//��������жϽ�����δ����Ԫ�ؽ�����˵�����������ź��������ٽ�����һ�˵�ð������ 
		{
			return;
		}
	}
}

int main()
{
	srand((int)time(0));
	int sz = 0;
	printf("�����������С��\n");
	scanf("%d",&sz);
	int * arr = NULL;
	arr =(int*)malloc(sizeof(int)*sz);
	int i = 0;
	printf("ԭ����˳��Ϊ��\n");
	for( i = 0; i< sz; i++)
	{
		arr[i] = rand()%100;
		printf("%d ",arr[i]);
	}
	printf("\n");
	Bubble_sort(arr, sz, sizeof(arr[0]), cmp);
	printf("���������˳��Ϊ��\n");
	for(i = 0; i< sz; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
