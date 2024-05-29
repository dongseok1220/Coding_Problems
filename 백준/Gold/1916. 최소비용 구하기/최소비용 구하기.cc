#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int N, M; 
int s, e; 
const int INF = numeric_limits<int>::max();

vector<int> path(int s, vector<vector<pair<int,int>>> bus, vector<int> &dist) { 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[s] = 0; 
    pq.push({0,s}); 

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int u = pq.top().second; 
        pq.pop(); 

        if (cur_dist > dist[u]) continue; // 더 길면 패스 

        for (auto &e : bus[u]) {
            int v = e.first; 
            int w = e.second; 

            if (dist[u] + w < dist[v]) { // v로 가는 경로가 더 짧으면 업데이트
                dist[v] = dist[u] + w; 
                pq.push({dist[v], v}); 
            }
        }
    }
    return dist; 
}

int main() {
    cin >> N >> M; 
    vector<vector<pair<int,int>>> bus; 
    bus.resize(N+1); 

    for (int i=0; i<M; i++) {
        int u,v, cost; 
        cin >> u >> v >> cost; 
        bus[u].push_back({v, cost}); 
    }

    cin >> s >> e; 
    
    vector<int> dist(N+1, INF); 
    path(s, bus, dist); 

    cout << dist[e];

    return 0; 
}

