#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int dx = -1; 
int dy[] = {-1, 0, 1}; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; 

    cin >> N; 

    vector<int> cur(3); 
    vector<int> max_dp(3,0); 
    vector<int> min_dp(3,0); 

    for (int i=0; i<N; i++) {
        cin >> cur[0] >> cur[1] >> cur[2]; 

        int temp0 = min_dp[0]; 
        int temp1 = min_dp[1]; 
        int temp2 = min_dp[2]; 

        min_dp[0] = min(temp0, temp1) + cur[0];
        min_dp[1] = min(min(temp0, temp1), temp2) + cur[1]; 
        min_dp[2] = min(temp1, temp2) + cur[2];

        temp0 = max_dp[0]; 
        temp1 = max_dp[1]; 
        temp2 = max_dp[2]; 

        max_dp[0] = max(temp0, temp1) + cur[0];
        max_dp[1] = max(max(temp0, temp1), temp2) + cur[1];
        max_dp[2] = max(temp1, temp2) + cur[2];
    }
    
    cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
    return 0;
}

