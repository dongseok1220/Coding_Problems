#include<iostream>

using namespace std; 

#define up 1
#define left 2
#define diagonal 3 // up+left 

int main(void)
{
	string str1, str2;

	cin >> str1; 
	cin >> str2; 

	int n = str1.length(); 
	int m = str2.length(); 

	int** dp = new int* [n+1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int [m+1]; 

	int** path = new int* [n + 1];
	for (int i = 0; i <= n; i++)
		path[i] = new int[m + 1];

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
		path[i][0] = up;
	}
	for (int i = 0; i <= m; i++) {
		path[0][i] = left;
		dp[0][i] = 0;
	}
		
	// dp[i][j] = i개의 str1과 j개의 str2의 LCS 
	// 따라서 dp[i][j] = 현재 str1 == str2 라면 이전 LCS + 1 
	// 서로 다르다면 이전 값 중 큰 값 할당 
	// i랑 j가 둘다 0이면 0을 줌 -> 인덱스가 1부터 시작임 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) { // 같으면 
				dp[i][j] = dp[i - 1][j - 1] + 1; 
				path[i][j] = diagonal;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1];
				path[i][j] = 0; 
			}
			if (dp[i - 1][j] >= dp[i][j]) {
				dp[i][j] = dp[i - 1][j];
				path[i][j] = up;
			}
			if (dp[i][j - 1] >= dp[i][j]) {
				dp[i][j] = dp[i][j - 1];
				path[i][j] = left; 
			}
		}
	}
	cout << dp[n][m] << endl;

	int pos = dp[n][m];
	int i = n, j = m;
	char* lcs = new char[pos + 1];

	if (pos) {
		lcs[pos--] = NULL; 

		while (i > 0 || j > 0) {
			if (path[i][j] == diagonal) {
				i--;
				j--;
				lcs[pos--] = str1[i]; 
			}
			else if (path[i][j] == up) {
				i--;
			}
			else if (path[i][j] == left) {
				j--; 
			}
		}
		cout << lcs << endl;
	}

 
	for (int i = 0; i <= n; i++)
		delete[] dp[i];
	delete[] dp; 

	for (int i = 0; i <= n; i++)
		delete[] path[i];
	delete[] path;
}