// ccf_buildsubway.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>  
#include<stdlib.h>  
int cmp(const void *i, const void *j);
long parent(long x);
#define MAX 200009
long n, m, ass[100002];
struct node//定义结构体存数据  
{
	long a, b, c;
}ss[MAX], temp;
long parent(long x)//寻找根节点  
{
	if (ass[x] == x)
		return x;
	return parent(ass[x]);
}
int cmp(const void *i, const void *j)//快速排序的比较函数  
{
	return(((struct node*)i)->c - ((struct node*)j)->c);
}
main()
{
	long i;
	scanf("%ld%ld", &n, &m);
	for (i = 0; i<m; i++)
		scanf("%ld%ld%ld", &ss[i].a, &ss[i].b, &ss[i].c);
	qsort(ss, m, sizeof(ss[0]), cmp);//将结构体由小到大排序，便于使用最小生成树  
	for (i = 1; i<n + 1; i++)//并查集初始化，每个节点都是根节点  
		ass[i] = i;
	for (i = 0; i<m; i++)//最小生成树  
	{
		ass[ss[i].a] = parent(ss[i].a);//压缩节点  
		ass[ss[i].b] = parent(ss[i].b);//压缩节点  
		if (ass[ss[i].a] != ass[ss[i].b])//判断两节点是否连接  
		{
			ass[ass[ss[i].a]] = ss[i].b;//将两节点连起来  

		}
		if (ss[i].c>ss[0].c)//选取最大的时间  
			ss[0].c = ss[i].c;
		ass[1] = parent(1);
		ass[n] = parent(n);
		if (ass[1] == ass[n])//看1和n是否连接  
			break;
	}
	printf("%d", ss[0].c);
	return(0);
}
