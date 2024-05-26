#include <iostream> 
#include <vector>
#include <deque> 

using namespace std; 

int N, M; 
int dx[4] = {1, -1, 0, 0}; 
int dy[4] = {0, 0, 1, -1}; 

bool check(vector<vector<int>> &map, int cur_x, int cur_y) {
    int cnt = 0; 
    for (int i=0; i<4; i++) {
        int nx = cur_x + dx[i]; 
        int ny = cur_y + dy[i]; 

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == -1) {
            cnt++; 
        }
    }
    if (cnt >= 2) return true; 
    else return false; 
}

void bfs(vector<vector<int>> &map) { 
    deque<pair<int,int>> q; 
    vector<vector<bool>> visited(N, vector<bool> (M, false)); 

    q.push_back({0,0}); 
    visited[0][0] = true; 
    map[0][0] = -1; 

    while (!q.empty()) {
        auto cur = q.front(); 
        q.pop_front(); 
        
        int cur_x = cur.first; 
        int cur_y = cur.second; 

        for (int i=0; i<4; i++) {
            int nx = cur_x + dx[i]; 
            int ny = cur_y + dy[i]; 

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true; 
                q.push_back({nx, ny}); 
                map[nx][ny] = -1; 
            }
        }
    }
}

int main() {
    cin >> N >> M; 

    vector<vector<int>> map(N, vector<int>(M));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0; 
    while (1) {
        bfs(map); 
        int cnt = 0; 
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (map[i][j] == 1) { // 1이면 
                    if (check(map, i, j)) map[i][j] = 0; // true면 
                    else cnt++; 
                }
            }
        }
        for (int i=0; i< N; i++) {
            for (int j=0; j<M; j++) {
                if (map[i][j] == -1) map[i][j] = 0; 
            }
        }
        ans++; 
        if (cnt == 0) break; 
    }

    cout << ans;
        

    return 0; 
}