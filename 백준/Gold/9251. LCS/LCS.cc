#include<iostream>

using namespace std; 

#define up 1;
#define left 2;
#define diagonal 3; // up+left 

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

	for (int i = 0; i <= n; i++)
		delete[] dp[i];
	delete[] dp; 

	for (int i = 0; i <= n; i++)
		delete[] path[i];
	delete[] path;
}