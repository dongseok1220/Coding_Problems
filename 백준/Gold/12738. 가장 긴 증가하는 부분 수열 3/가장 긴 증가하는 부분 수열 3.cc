#include<iostream>
#include <algorithm>

using namespace std; 

int check(int *path, int num, int cnt) {
    int s = 0; 
    int e = cnt - 1; 
    int mid;
    while(1) { 
        mid = (s + e) / 2;
        if (path[mid] < num) { 
            s = mid + 1; 
        }
        else e = mid; 
        
        if (s >= e) {
            if (path[s] > num)
                path[s] = num; 
            
            return 1; 
        }
    }
    return 1; 
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
		dp[i] = 1;
		
    path[0] = arr[0]; 
    int cnt = 1; 
	// 1 과 0 <= j <= i-1 이고 a[j] < a[i] (증가)일 때 dp[i]가 dp[j] + 1 보다 작으면 dp[i] = dp[j] + 1 이 된다. 
	for (int i = 1; i < N; i++) {
	    if (path[cnt-1] < arr[i]) {
	        path[cnt] = arr[i];  
	        cnt++; 
	    }
		else check(path, arr[i], cnt); // path에서 arr[i]의 위치를 대체할 수 있는지 확인 
	}
	cout << cnt << endl;
    
    
	delete[] dp;
	delete[] path; 
	

	return 0;
}