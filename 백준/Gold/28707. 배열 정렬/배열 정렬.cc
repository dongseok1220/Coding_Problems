#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

int N, M;

int main() {
    cin >> N;

    vector<int> A(N+1); 
    for (int i=1; i<=N; i++) {
        cin >> A[i]; 
    } 

    cin >> M; 

    vector<int> l(M+1); 
    vector<int> r(M+1); 
    vector<int> c(M+1); 

    for (int i=1; i<=M; i++) {
        cin >> l[i] >> r[i] >> c[i];  
    } 

    priority_queue<pair<int, vector<int>>> pq; 
    map<vector<int>, int> dist; 

    dist[A] = 0; // 초기 상태 
    pq.push(make_pair(0, A)); 

    while(!pq.empty()) { 
        auto top = pq.top(); 
        int cost = top.first;
        vector<int> cur = top.second;
        pq.pop(); 

        if (dist[cur] >= -cost) { // 비용을 음수
            for (int i=1; i<=M; i++) {
                swap(cur[l[i]], cur[r[i]]);
                int new_cost = -cost + c[i];
                if (!dist.count(cur) || dist[cur] > new_cost) {
                    dist[cur] = new_cost;
                    pq.push(make_pair(-new_cost, cur));
                }
                swap(cur[l[i]], cur[r[i]]);
            }
        }
    }

    sort(A.begin(), A.end());

    if (dist.count(A)) cout << dist[A];
    else cout << -1; 
    
    return 0;
}
