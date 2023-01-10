#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palin[2501][2501];
int dp[2501] = { 0, } ;

int main(void) {
	char str[2501]; 
	scanf("%s", str);
	int n = strlen(str);
	
	for (int i = 0; i < n; i++)
		palin[i][i] = 1; // 자기자신 
	for (int i = 0; i < n-1; i++)
		if (str[i] == str[i+1]) palin[i][i+1] = 1; 

	for (int i = 2; i <= n; i++) { 
		for (int j = 0; i+j-1 <= n; j++) {
			if (str[j] == str[i+j-1] && palin[j+1][j+i-2])
				palin[j][j+i-1] = 1;
		}
	}
	/*
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			printf("%d ", palin[i][j]);
		printf("\n");
	}
	*/
	for (int i = 0; i < n; i++) {
		dp[i] = 1e9; 
		for (int j = 0; j <= i; j++) {
			if (palin[j][i]) {
				dp[i] = (dp[i] < dp[j-1] + 1) ? dp[i] : dp[j-1] + 1; 
			}
		}
	}
	printf("%d", dp[n-1]);
	

}