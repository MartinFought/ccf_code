// communication_network.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
using namespace std;
int n;

void floyd_warshall(int **e, int ***D) {
	int i, j, k;
	for (k = 1; k <= n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				D[k][i][j] = D[k - 1][i][j] | (D[k - 1][i][k - 1] & D[k - 1][k - 1][j]);
			}
		}
	}
}

int main()
{
	int m, i, j;
	cin >> n >> m;
	int **e, curRow, curCol;
	e = new int *[n];
	for (i = 0; i < n; i++) {
		e[i] = new int[n];
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (i == j) {
				e[i][j] = 1;
			}
			else { 
				e[i][j] = 0; 
			}
		}
	for (i = 0; i<m; i++) {
		cin >> curRow >> curCol;
		e[curRow - 1][curCol - 1] = 1;
	}

	int ***D = new int**[n + 1];//最短路径权重矩阵D
	int *col = new int[n];
	int *row = new int[n];
	memset(col, 0, sizeof(int)*n);
	memset(row, 0, sizeof(int)*n);
	for (i = 0; i <= n; i++) {
		D[i] = new int*[n];
		for (j = 0; j < n; j++) {
			D[i][j] = new int[n];
		}
	}//定义并初始化最短路径矩阵和前驱矩阵
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			D[0][i][j] = e[i][j];
		}
	}
	floyd_warshall(e, D);

	int num = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (D[n][i][j] == 1) {
				col[i]++;
				row[j]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (col[i] == n || row[i] == n || col[i] + row[i] - 1 == n) num++;
	}
	cout << num;
    return 0;
}
