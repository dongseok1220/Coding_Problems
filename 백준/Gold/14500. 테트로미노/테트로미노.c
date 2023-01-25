#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ( (a > b ? a : b) )

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int ans = 0;
int max_block(int** map, int** visited, int y, int x, int n, int m, int sum, int cnt)
{
	if (cnt == 4) {
		ans = max(ans, sum);
		//printf("%d", ans);
		return;
	}
	if (y < 0 || x < 0 || y >= n || x >= m) 
		return;

	if (visited[y][x]) return;

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		max_block(map,visited,y + dy[i], x + dx[i],n,m, sum + map[y][x], cnt + 1);
	}
	visited[y][x] = 0;
}

int main(void)
{
	int n, m;
	int block_1[2][3] = { { 1,1,1 }, { 0,1,0 } };
	int block_2[2][3] = { {0,1,0}, {1,1,1} };
	int block_3[3][2] = { {1,0}, {1,1}, {1,0} };
	int block_4[3][2] = { { 0,1}, {1,1}, {0,1} };

	scanf("%d %d", &n, &m);

	int** map;
	map = (int**)malloc(sizeof(int*) * n);

	int** visit;
	visit = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		map[i] = (int*)malloc(sizeof(int) * m);
		visit[i] = (int*)malloc(sizeof(int) * m);
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = 0;
		}

	int max = 0;
	int count = 0;
	int temp = 0;
	int temp_2 = 0;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			max_block(map, visit, i, j, n, m, 0, 0);
			if (j + 1 < m && j>=1) {
				temp = map[i][j - 1] + map[i][j] + map[i][j + 1];
			}
			if (i + 1 < n && i>=1) {
				temp_2 = map[i][j] + map[i - 1][j] + map[i + 1][j];
			}

			if (j - 1 >= 0 && max < temp_2 + map[i][j - 1])
				max = temp_2 + map[i][j - 1];
			else if (j + 1 < m && max < temp_2 + map[i][j + 1])
				max = temp_2 + map[i][j + 1];

			if (i>=1 && temp + map[i - 1][j] > max)
				max = temp + map[i - 1][j];
			else if (i + 1 < n && temp + map[i + 1][j] > max)
				max = temp + map[i + 1][j];

			if (max < ans) max = ans;

			temp = 0; 
			temp_2 = 0;
		}
	
	printf("%d", max);
}