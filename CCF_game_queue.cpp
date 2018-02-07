// CCF_game_queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<queue>


using namespace std;

int main() {

	int N, K, num = 1;
	queue<int> list;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		list.push(i);
	}

	while (list.size()>1) {
		int top = list.front();
		list.pop();
		if (num%K != 0 && (num - num / 10 * 10) != K) {
			list.push(top);
		}
		num++;
	}

	cout << list.front();
	return 0;
}