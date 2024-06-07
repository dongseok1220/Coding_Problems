#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int>& path, int num, int cnt, vector<int>& index, vector<int>& prev, int i) {
    int s = 0;
    int e = cnt - 1;
    int mid;
    while (1) {
        mid = (s + e) / 2;
        if (path[mid] < num) {
            s = mid + 1;
        } else e = mid;

        if (s >= e) {
            if (path[s] > num) {
                path[s] = num;
                index[s] = i;
                if (s > 0) prev[i] = index[s-1];
            }
            return 1;
        }
    }
    return 1;
}

int main() {
    int N;
    cin >> N;

    vector<int> dp(N);
    vector<int> arr(N);
    vector<int> path(N);
    vector<int> index(N);  
    vector<int> prev(N, -1); 

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++)
        dp[i] = 1;

    path[0] = arr[0];
    index[0] = 0;
    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (path[cnt - 1] < arr[i]) {
            path[cnt] = arr[i];
            index[cnt] = i;
            prev[i] = index[cnt-1];
            cnt++;
        } else {
            check(path, arr[i], cnt, index, prev, i); // path에서 arr[i]의 위치를 대체할 수 있는지 확인
        }
    }

    cout << cnt << endl;

    vector<int> lis;
    int k = index[cnt-1];
    while (k != -1) {
        lis.push_back(arr[k]);
        k = prev[k];
    }

    for (int i = cnt-1; i >= 0; i--) {
        cout << lis[i] << " ";
    }

    return 0;
}
