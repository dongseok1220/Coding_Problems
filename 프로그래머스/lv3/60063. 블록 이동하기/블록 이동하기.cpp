#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct robot {
	int time;
	int x;
	int y;
	int type; // 0 : 가로, 1 : 세로
};
bool check(int x, int y, int type);
int visit[101][101][2]; // 0 : 가로, 1 : 세로
int dx[] = { -1, 1, 0, 0 }; //상 하 좌 우
int dy[] = { 0, 0, -1, 1 };
vector<vector<int> > table;


bool check(int x, int y, int type) { // 범위를 벗어나거나, 벽에 부딪히면 false
	int N = table.size();
	if (type == 0) {//가로
		if (x < 0 || y < 0 || x >= N || y + 1 >= N) return false;
		if (table[x][y] || table[x][y + 1]) return false;
	}
	else {//세로
		if (x < 0 || y < 0 || x + 1 >= N || y >= N) return false;
		if (table[x][y] || table[x + 1][y]) return false;
	}
	return true;
}
int solution(vector<vector<int>> board) {
	int answer = 0, N = board.size(); 
	table = board;

	memset(visit, 0, sizeof(visit));

	queue<robot> q;
	q.push({ 0, 0, 0, 0 });
	while (!q.empty()) {
		robot now = q.front(); 
		q.pop();
		if ((now.type == 0 && now.x == N - 1 && now.y == N - 2) || (now.type == 1 && now.x == N - 2 && now.y == N - 1)) {
			return now.time;
		}

		for (int i = 0; i < 4; i++) { // 상하좌우 이동
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (!check(nx, ny, now.type) || visit[nx][ny][now.type]) continue; //이전에 방문한 적 있으면 건너뛰기
			visit[nx][ny][now.type] = 1;
			q.push({ now.time + 1, nx, ny, now.type });
		}

		//여기부터 회전
		if (now.type == 0) { //가로
			//오른쪽 칸이 축
			if (now.x + 1 <= N - 1 && !table[now.x + 1][now.y] && !table[now.x + 1][now.y + 1] && !visit[now.x][now.y + 1][1]) {
				q.push({ now.time + 1, now.x, now.y + 1, 1 });
			}
			if (now.x - 1 >= 0 && !table[now.x - 1][now.y] && !table[now.x - 1][now.y + 1] && !visit[now.x - 1][now.y + 1][1]) {
				q.push({ now.time + 1, now.x - 1, now.y + 1, 1 });
			}
			//왼쪽 칸이 축
			if (now.x + 1 <= N - 1 && !table[now.x + 1][now.y + 1] && !table[now.x + 1][now.y] && !visit[now.x][now.y][1]) {
				q.push({ now.time + 1, now.x, now.y, 1 });
			}
			if (now.x - 1 >= 0 && !table[now.x - 1][now.y + 1] && !table[now.x - 1][now.y] && !visit[now.x - 1][now.y][1]) {
				q.push({ now.time + 1, now.x - 1, now.y, 1 });
			}
		}
		else { //세로
		    //아래칸이 축
			if (now.y - 1 >= 0 && !table[now.x][now.y - 1] && !table[now.x + 1][now.y - 1] && !visit[now.x + 1][now.y - 1][0]) {
				q.push({ now.time + 1, now.x + 1, now.y - 1, 0 });
			}
			if (now.y + 1 <= N - 1 && !table[now.x][now.y + 1] && !table[now.x + 1][now.y + 1] && !visit[now.x + 1][now.y][0]) {
				q.push({ now.time + 1, now.x + 1, now.y, 0 });
			}
			//위 칸이 축
			if (now.y - 1 >= 0 && !table[now.x + 1][now.y - 1] && !table[now.x][now.y - 1] && !visit[now.x][now.y - 1][0]) {
				q.push({ now.time + 1, now.x, now.y - 1, 0 });
			}
			if (now.y + 1 <= N - 1 && !table[now.x + 1][now.y + 1] && !table[now.x][now.y + 1] && !visit[now.x][now.y][0]) {
				q.push({ now.time + 1, now.x, now.y, 0 });
			}
		}
	}
}