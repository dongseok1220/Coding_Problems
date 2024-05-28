#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;
int age = 2; // 아기상어 나이
int eat = 0, fish_cnt = 0;

int dx[4] = {-1, 0, 0, 1}; // 거리가 같을 때 위, 왼쪽이 우선순위
int dy[4] = {0, -1, 1, 0};

pair<int, int> baby;

int bfs(vector<vector<int>> &aqua) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    pq.push({0, baby});
    visited[baby.first][baby.second] = true;

    while (!pq.empty()) {
        int cur_ans = pq.top().first;
        int cur_x = pq.top().second.first;
        int cur_y = pq.top().second.second;
        pq.pop();

        if (aqua[cur_x][cur_y] < age && aqua[cur_x][cur_y] != 0) { // 먹을 수 있으면
            eat++;
            if (eat == age) {
                age++;
                eat = 0;
            }
            fish_cnt--;
            baby = {cur_x, cur_y};
            aqua[cur_x][cur_y] = 0;
            return cur_ans;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && aqua[nx][ny] <= age) {
                visited[nx][ny] = true;
                pq.push({cur_ans + 1, {nx, ny}});
            }
        }
    }
    return 0;
}

int main() {
    cin >> N;

    vector<vector<int>> aqua(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> aqua[i][j];
            if (aqua[i][j] == 9) {
                baby = {i, j};
                aqua[i][j] = 0;
            } else if (aqua[i][j] != 0) {
                fish_cnt++;
            }
        }
    }

    if (fish_cnt == 0) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    while (fish_cnt != 0) {
        int k = bfs(aqua);
        if (k == 0) break;
        ans += k;
    }
    cout << ans;

    return 0;
}
