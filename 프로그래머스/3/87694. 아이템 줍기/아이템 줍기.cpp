#include <string>
#include <vector>
#include <deque> 

using namespace std;

int bfs(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    int dx[] = {1, -1, 0, 0}; 
    int dy[] = {0, 0, 1, -1}; 
    int n = grid.size();
    int m = grid[0].size(); 
    
    deque<pair<pair<int,int>, int>> q; // x,y, distance
    q.push_back({start, 0}); 
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true; 
    
    while (!q.empty()) { 
        auto [pos, dist] = q.front(); 
        q.pop_front(); 
        
        int x = pos.first; 
        int y = pos.second; 
        
        if (x == end.first && y == end.second) 
            return dist; 
        
        for (int i = 0; i < 4; i++) { 
            int nx = x + dx[i];
            int ny = y + dy[i]; 
            
            if (nx >= 0 && nx < n && ny >=0 && ny < m && !visited[nx][ny] && grid[nx][ny]) {
                visited[nx][ny] = true; 
                q.push_back({{nx,ny}, dist+1}); 
            }
        }
    }
    
    return -1; 
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> grid(102, vector<int>(102, 0));
    
    // 직사각형의 테두리 표시
    for (const auto& rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;
        
        for (int i = x1; i <= x2; ++i) {
            grid[i][y1] = 1;
            grid[i][y2] = 1;
        }
        for (int i = y1; i <= y2; ++i) {
            grid[x1][i] = 1;
            grid[x2][i] = 1;
        }
    }
    
    for (const auto& rect : rectangle) {
        int x1 = rect[0] * 2;
        int y1 = rect[1] * 2;
        int x2 = rect[2] * 2;
        int y2 = rect[3] * 2;

        for (int i = x1 + 1; i < x2; ++i) {
            for (int j = y1 + 1; j < y2; ++j) {
                grid[i][j] = 0;
            }
        }
    }
    // 시작점과 종료점 설정
    pair<int, int> start = {characterX * 2, characterY * 2};
    pair<int, int> end = {itemX * 2, itemY * 2};

    answer = bfs(grid, start, end) / 2;
    
    return answer;
}