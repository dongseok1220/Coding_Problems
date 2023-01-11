#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
	int r;
	int c; 
}Matrix;

int main(void)
{
	int N; 
	scanf("%d", &N);

	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix) * N+1); 
	int* data = (int*)malloc(sizeof(int) * N+1); 
	for (int i = 1; i <= N; i++) { // 순서는 동일함 
		scanf("%d %d", &matrix[i].r, &matrix[i].c);
		data[i-1] = matrix[i].r; 
	}
	data[N] = matrix[N].c;

	int** dp = (int**)malloc(sizeof(int*) * N+1); 
	// the minimum number of multiplications needed to multiply A_i through A_j
	// dp[1][N] 
	for (int i = 0; i <= N; i++)
		dp[i] = (int*)malloc(sizeof(int) *N+1);
	
	// dp[i][j] = min i<=k <= j-1 { dp[i][k] + dp[k+1][j] + d_i-1d_kd_j  
	//				0 if i== j
	// A_i = d_i-1 * d_i = matrix[i].r * matrix[i].c

	
	int j,temp; 
	for (int i = 1; i <= N; i++) dp[i][i] = 0; 
	for (int g=1; g <= N - 1; g++) {
		for (int i = 1; i <= N - g; i++) {
			j = i + g; 
			dp[i][j] = 1e9; // 매우 큰수 
			for (int k = i; k <= j - 1; k++)
				if ((temp = dp[i][k] + dp[k + 1][j] + data[i - 1] * data[k] * data[j]) < dp[i][j]) {
					dp[i][j] = temp;
				}
		}
	}
	
	printf("%d", dp[1][N]);
	


	free(data);
	free(matrix);
	for (int i = 0; i < N; i++)
		free(dp[i]);
	free(dp);

	return 0;
}