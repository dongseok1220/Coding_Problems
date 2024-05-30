#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int N, M; 
int s; 
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M; 
    vector<vector<pair<int,int>>> bus; 
    bus.resize(N+1); 

    cin >> s;


    for (int i=0; i<M; i++) {
        int u,v, cost; 
        cin >> u >> v >> cost; 
        bus[u].push_back({v, cost}); 
    }
    
    vector<int> dist(N+1, INF); 
    path(s, bus, dist); 

    for (int i=1; i<=N; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
            continue;
        }
        cout << dist[i] << endl;
    }

    return 0; 
}

