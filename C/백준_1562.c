#define _CRT_SECURE_NO_WARNINGS
#define mod 1000000000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[10] = { 0, };
int count = 0;

int stair(int n, int countNum, int N, int* nCase);
void main()
{
	// 0~9까지 모두 들어가있는지 확인 -> 1로 바뀌면 ㅇㅇ

	int N;
	int num = 0;
	int* nCase = &num;

	scanf("%d", &N);

	int i, j;

	for (i = 1; i <= 9; i++)
	{
		stair(i, 1, N, nCase);

	}
	//   stair(9, 1, N, nCase);
	printf("%d\n", (*nCase) % mod);
}

int stair(int n, int countNum, int N, int* nCase)
{
	int i;
	(*nCase) = (*nCase) % mod;
	a[n]++;
	if (countNum == N) {
		if (a[0] == 0 || a[9] == 0) {
			a[n]--;
			return 0;
		}
		a[n]--;
		(*nCase)++;
		return 0;
	}
	if (n == 0)
	{
		countNum++;
		stair(1, countNum, N, nCase);
	}
	else if (n == 9)
	{
		countNum++;
		stair(8, countNum, N, nCase);
	}
	else {
		countNum++;
		stair(n - 1, countNum, N, nCase);
		stair(n + 1, countNum, N, nCase);
	}
	a[n]--;
	countNum--;
	return 1;
}