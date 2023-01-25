#include<iostream>
#include <algorithm>

using namespace std; 


int main()
{
	int N, K;
	cin >> N >> K;

	int* w = new int[N+1];
	int* p = new int[N+1];

	for (int i = 1; i <= N; i++)
		cin >> w[i] >> p[i]; // 무게 & 가치 

	int** dp = new int* [N+1];
	for (int i = 0; i <= N; i++)
		dp[i] = new int[K+1]; 

	for (int i = 1; i <= K; i++) dp[0][i] = 0;

	for (int i = 1; i <= N; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= K; j++) {
			if (w[i] <= j) { // 넣을 수 있으면 
				dp[i][j] = max(p[i] + dp[i - 1][j - w[i]], dp[i - 1][j]); // 넣은 것과 안넣는 것 둘 비교 
			}
			else dp[i][j] = dp[i - 1][j]; // 못넣으면 이전값 그대로 가져감 
		}
	}
	cout << dp[N][K];



	for (int i = 0; i <= N; i++)
		delete[] dp[i];
	delete[] dp;

	delete[] w;
	delete[] p;

	return 0;
}