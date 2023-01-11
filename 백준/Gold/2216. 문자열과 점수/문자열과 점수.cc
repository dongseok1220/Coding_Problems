#include<iostream>
#include <algorithm>

using namespace std; 

int main()
{
	string str1, str2; 

	int s, p, f; // 같을때, 공백, 다를 때 

	cin >> s >> p >> f;
	cin >> str1;
	cin >> str2; 

	int n = str1.length();
	int m = str2.length(); 

	int** dp = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int[m + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0) dp[i][j] = j * p;
			if (j == 0) dp[i][j] = i * p; 

			if (i > 0 && j > 0) {
				int check = str1[i-1] == str2[j-1] ? s : f; 
				// 같으면 s 를 다르면 f를 
				// 아니면 공백 값 p를 
				dp[i][j] = max(dp[i - 1][j - 1] + check, max(dp[i][j - 1] + p, dp[i - 1][j] + p)); 
			}
		}
	}

	cout << dp[n][m];

	for (int i = 0; i <= n; i++)
		delete[] dp[i];
	delete[] dp; 

	return 0;
}