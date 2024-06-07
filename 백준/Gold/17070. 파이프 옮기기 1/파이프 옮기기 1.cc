#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Pair {
    int first[2];
    int second[2];
};

int check_dir(Pair a) {
    if (a.first[0] == a.second[0]) { // x좌표가 동일 -> 가로
        return 1;
    } else if (a.first[1] == a.second[1]) { // y좌표가 동일 -> 세로
        return 2;
    }
    return 3; // 아니면 대각선
}

bool can_move(int x, int y, vector<vector<int>>& state) {
    return x >= 1 && x < state.size() && y >= 1 && y < state.size() && state[x][y] == 0;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> state(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> state[i][j];
        }
    }

    deque<Pair> pipe;
    pipe.push_back({{1, 1}, {1, 2}});

    int cnt = 0;

    while (!pipe.empty()) {
        Pair cur = pipe.front();
        pipe.pop_front();

        if (cur.second[0] == N && cur.second[1] == N) {
            cnt++;
            continue;
        }

        int check = check_dir(cur);
        Pair next;

        if (check == 1) { // 가로
            // 오른쪽 이동
            if (can_move(cur.second[0], cur.second[1] + 1, state)) {
                next = cur;
                next.first[1]++;
                next.second[1]++;
                pipe.push_back(next);
            }
            // 대각선 이동
            if (can_move(cur.second[0], cur.second[1] + 1, state) &&
                can_move(cur.second[0] + 1, cur.second[1], state) &&
                can_move(cur.second[0] + 1, cur.second[1] + 1, state)) {
                next = cur;
                next.first[1]++;
                next.second[0]++;
                next.second[1]++;
                pipe.push_back(next);
            }
        } else if (check == 2) { // 세로
            // 아래로 이동
            if (can_move(cur.second[0] + 1, cur.second[1], state)) {
                next = cur;
                next.first[0]++;
                next.second[0]++;
                pipe.push_back(next);
            }
            // 대각선 이동
            if (can_move(cur.second[0], cur.second[1] + 1, state) &&
                can_move(cur.second[0] + 1, cur.second[1], state) &&
                can_move(cur.second[0] + 1, cur.second[1] + 1, state)) {
                next = cur;
                next.first[0]++;
                next.second[0]++;
                next.second[1]++;
                pipe.push_back(next);
            }
        } else if (check == 3) { // 대각선
            // 오른쪽 이동 (가로로 변경)
            if (can_move(cur.second[0], cur.second[1] + 1, state)) {
                next = cur;
                next.first[0] = cur.second[0];
                next.first[1] = cur.second[1];
                next.second[1]++;
                pipe.push_back(next);
            }
            // 아래로 이동 (세로로 변경)
            if (can_move(cur.second[0] + 1, cur.second[1], state)) {
                next = cur;
                next.first[0] = cur.second[0];
                next.first[1] = cur.second[1];
                next.second[0]++;
                pipe.push_back(next);
            }
            // 대각선 이동 (대각선 유지)
            if (can_move(cur.second[0], cur.second[1] + 1, state) &&
                can_move(cur.second[0] + 1, cur.second[1], state) &&
                can_move(cur.second[0] + 1, cur.second[1] + 1, state)) {
                next = cur;
                next.first[0]++;
                next.first[1]++;
                next.second[0]++;
                next.second[1]++;
                pipe.push_back(next);
            }
        }
    }

    cout << cnt;

    return 0;
}
