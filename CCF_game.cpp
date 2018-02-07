// CCF_game.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int baoshu(int *num, int n,int k)
{
	int left = n, count = 1;
	int i, j;
	for (i = 0;left>1; i++) {
		if (num[i%n] == 0) {

		}
		else if (count%k == 0 || count%10 == k) {
			num[i%n] = 0;
			left--;
			count++;
		}
		else {
			num[i%n] = count;
			count++;
		}
	}
	for (i = 0; i < n; i++) {
		if (num[i] != 0) {
			break;
		}
	}
	return i;
}

int main()
{
	int n, k, left;
	cin >> n >> k;
	int *num = new int[n];
	memset(num, 1, sizeof(num));
	left = baoshu(num, n, k);
	cout << left + 1;
    return 0;
}

