#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100000;

int bfs(int N, int K) {
    vector<int> visited(MAX + 1, -1);
    queue<int> q;

    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 세 가지 이동 가능성 검사
        int positions[3] = {current * 2, current + 1, current - 1};
        int times[3] = {visited[current], visited[current] + 1, visited[current] + 1};

        for (int i = 0; i < 3; ++i) {
            if (positions[i] >= 0 && positions[i] <= MAX) {
                if (visited[positions[i]] == -1 || visited[positions[i]] > times[i]) {
                    visited[positions[i]] = times[i];
                    q.push(positions[i]);
                }
            }
        }
    }
    return visited[K];
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << bfs(N, K);

    return 0;
}
