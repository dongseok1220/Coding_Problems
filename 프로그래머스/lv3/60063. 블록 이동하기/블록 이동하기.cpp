#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream> 

using namespace std;

// 로봇의 움직임은 총 8가지가 가능하다.
// 따라서, 기존 BFS의 방문배열과 다르게 3차원 배열로 한다. 또한 queue를 사용함
// BFS로 구현할 것이다. 따라서 현재 위치에서 상/하/좌/우 및 회전이 가능할 경우
// 가능한 모든 위치를 push해줌 

struct Robot{
    int y,x; // 로봇의 좌표이며, (y,x)로 생각한다. 
    int state; // 0이면 가로 1이면 세로를 의미한다. 
    int ans; 
};

bool check_pos(vector<vector<int>> board, int ny, int nx, int state, int N) {
    // 가로 일 경우 ny,nx와 ny, nx+1 검사 
    if  (state == 0) {
        if (nx < 0 || ny < 0 || nx + 1 >= N || ny >= N) return false; 
        if (board[ny][nx] || board[ny][nx+1]) return false; 
    }
    // 세로 일 경우 ny,nx와 ny+1, nx 검사 
    else {
        if (nx < 0 || ny < 0 || nx >= N || ny + 1 >= N) return false; 
        if (board[ny][nx] || board[ny+1][nx]) return false; 
    }
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int visit[101][101][2]; 
    memset(visit,0, sizeof(visit));
    
    int N = board.size(); 
    
    queue<Robot> robot; 
    robot.push({0,0,0,0}); 
    
    int dx[4] = { -1, 1, 0, 0 }; 
    int dy[4] = { 0, 0, -1, 1 };
    
    while (robot.size() != 0) {
        Robot cur = robot.front();
        robot.pop(); 
        
        // 종료조건 
        if ((cur.state == 0 && cur.y == N-1 && cur.x == N-2) || (cur.state == 1 && cur.y == N-2 && cur.x == N-1))
            return cur.ans;
        
        // 우선 상/하/좌/우 체크 
        for (int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i]; 
            // 방문한적이 있거나 or 이동할 수 없다면 continue
            if (!check_pos(board, ny,nx, cur.state,N) || visit[ny][nx][cur.state]) 
                continue; 
            // 위 조건이 아니라면 방문함 
            visit[ny][nx][cur.state] = 1; 
            robot.push({ny,nx,cur.state, cur.ans+1}); 
        }
        
        // 현재 위치에서 회전이 가능한 경우 모두 push해준다! 
        int y = cur.y; 
        int x = cur.x; 
        int ans = cur.ans + 1; 
        
        // 현재 가로일 경우
        switch (cur.state) {
            case 0 :
        // 왼쪽을 축으로 회전할 경우
            // 1. 아래로 회전 
                // y,x를 기준으로 board의 y+1과 x+1의 값, y+1, x의 값을 확인한다.
                // 또한 y+1 <= N-1 이고 x+1 <= N-1이어야 한다.
                // 또한, 방문의 경우 visit[y][x][1]일 때를 확인한다. 
                if (y+1 <= N-1 && !board[y+1][x] && !board[y+1][x+1] && !visit[y][x][1])
                    robot.push({y,x,1,ans});
            // 2. 위로 회전 
                // y,x를 기준으로 board의 y-1과 x의 값, y-1,x+1의 값을 확인한다. 
                // 또한 y-1 >=0 이고 x+1 <= N-1 이어야 한다. 
                // 이번에는 방문의 경우 visit[y-1][x][1]일 때를 확인한다. 
                if (y-1 >= 0 && !board[y-1][x] && !board[y-1][x+1] && !visit[y-1][x][1])
                    robot.push({y-1,x,1,ans});
        // 오른쪽을 축으로 회전할 경우 
            // 1. 아래로 회전 
                // y,x를 기준으로 board의 y+1과 x의 값, y+1, x+1의 값을 확인한다.
                // 또한 y+1 <= N-1 이고 x+1 <= N-1이어야 한다.
                // 또한, 방문의 경우 visit[y][x+1][1]일 때를 확인한다. 
                if (y+1 <= N-1 && !board[y+1][x] && !board[y+1][x+1] && !visit[y][x+1][1])
                    robot.push({y,x+1,1,ans});
            // 2. 위로 회전
                // y,x를 기준으로 board의 y-1과 x의 값, y-1,x+1의 값을 확인한다. 
                // 또한 y-1 >=0 이고 x+1 <= N-1 이어야 한다. 
                // 이번에는 방문의 경우 visit[y-1][x+1][1]일 때를 확인한다. 
                if (y-1 >= 0  && !board[y-1][x] && !board[y-1][x+1] && !visit[y-1][x+1][1])
                    robot.push({y-1,x+1,1,ans});
                break;
        // 현재 세로일 경우
            case 1 :
        // 위쪽을 축으로 회전할 경우
            // 1. 오른쪽으로 회전 
                // y,x를 기준으로 board의 y과 x+1의 값, y+1, x+1의 값을 확인한다.
                // 또한 y+1 <= N-1 이고 x+1 <= N-1이어야 한다.
                // 또한, 방문의 경우 visit[y][x][0]일 때를 확인한다. 
                if (x+1 <= N-1 && !board[y][x+1] && !board[y+1][x+1] && !visit[y][x][0])
                    robot.push({y,x,0,ans});
            // 2. 왼쪽으로 회전 
                // y,x를 기준으로 board의 y과 x-1의 값, y+1,x-1의 값을 확인한다. 
                // 또한 y+1 <= N-1 이고 x-1 >= 0 이어야 한다. 
                // 이번에는 방문의 경우 visit[y][x-1][0]일 때를 확인한다. 
                if (x-1 >= 0 && !board[y+1][x-1] && !board[y][x-1] && !visit[y][x-1][0])
                    robot.push({y,x-1,0,ans});
        // 아래쪽을 축으로 회전할 경우 
            // 1. 오른쪽으로 회전 
                // y,x를 기준으로 board의 y과 x+1의 값, y+1, x+1의 값을 확인한다.
                // 또한 y+1 <= N-1 이고 x+1 <= N-1이어야 한다.
                // 또한, 방문의 경우 visit[y+1][x][0]일 때를 확인한다. 
                if (x+1 <= N-1 && !board[y][x+1] && !board[y+1][x+1] && !visit[y+1][x][0])
                    robot.push({y+1,x,0,ans});
            // 2. 왼쪽으로 회전
                // y,x를 기준으로 board의 y과 x-1의 값, y+1,x-1의 값을 확인한다. 
                // 또한 y+1 <= N-1 이고 x-1 >= 0 이어야 한다. 
                // 이번에는 방문의 경우 visit[y+1][x-1][0]일 때를 확인한다. 
                if (x-1 >= 0 && !board[y][x-1] && !board[y+1][x-1] && !visit[y+1][x-1][0])
                    robot.push({y+1,x-1,0,ans});
                break;
        }
    }

}
