// ccf_buildsubway.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>  
#include<stdlib.h>  
int cmp(const void *i, const void *j);
long parent(long x);
#define MAX 200009
long n, m, ass[100002];
struct node//����ṹ�������  
{
	long a, b, c;
}ss[MAX], temp;
long parent(long x)//Ѱ�Ҹ��ڵ�  
{
	if (ass[x] == x)
		return x;
	return parent(ass[x]);
}
int cmp(const void *i, const void *j)//��������ıȽϺ���  
{
	return(((struct node*)i)->c - ((struct node*)j)->c);
}
main()
{
	long i;
	scanf("%ld%ld", &n, &m);
	for (i = 0; i<m; i++)
		scanf("%ld%ld%ld", &ss[i].a, &ss[i].b, &ss[i].c);
	qsort(ss, m, sizeof(ss[0]), cmp);//���ṹ����С�������򣬱���ʹ����С������  
	for (i = 1; i<n + 1; i++)//���鼯��ʼ����ÿ���ڵ㶼�Ǹ��ڵ�  
		ass[i] = i;
	for (i = 0; i<m; i++)//��С������  
	{
		ass[ss[i].a] = parent(ss[i].a);//ѹ���ڵ�  
		ass[ss[i].b] = parent(ss[i].b);//ѹ���ڵ�  
		if (ass[ss[i].a] != ass[ss[i].b])//�ж����ڵ��Ƿ�����  
		{
			ass[ass[ss[i].a]] = ss[i].b;//�����ڵ�������  

		}
		if (ss[i].c>ss[0].c)//ѡȡ����ʱ��  
			ss[0].c = ss[i].c;
		ass[1] = parent(1);
		ass[n] = parent(n);
		if (ass[1] == ass[n])//��1��n�Ƿ�����  
			break;
	}
	printf("%d", ss[0].c);
	return(0);
}
