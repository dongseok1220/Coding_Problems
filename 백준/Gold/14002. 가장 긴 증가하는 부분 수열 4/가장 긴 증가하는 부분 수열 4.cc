#include<iostream>
#include <algorithm>

using namespace std; 

void print(int index, int *path, int *arr) {
	if (index == -1) return;
	print(path[index],path,arr);
	cout << arr[index] << ' ';
}
int main()
{
	int N;
	cin >> N; 

	// dp는 0~i까지 최장 부분수열 길이 저장 
	int* dp = new int[N]; 

	// 입력 배열
	int* arr = new int[N];
	int* path = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i]; 
	for (int i = 0; i < N; i++)
		dp[i] = 1, path[i] = -1;

	// 1 과 0 <= j <= i-1 이고 a[j] < a[i] (증가)일 때 dp[i]가 dp[j] + 1 보다 작으면 dp[i] = dp[j] + 1 이 된다. 

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1; 
				path[i] = j;
			}
		}
	}
	int index= 0, max=0;
	for (int i =0; i< N; i++) 
		if (max < dp[i]) {
			max = dp[i];
			index = i;
		}

	cout << max << endl;

	print(index,path,arr);

	delete[] dp;
	delete[]path;
	

	return 0;
}