#include<vector>
#include <deque> 
#include <iostream> 

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    deque<pair<int, int>> q; 
    int n = maps.size();
    int m = maps[0].size(); 
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    q.push_back({0,0}); // start 
    visited[0][0] = true; 
    answer++; 
    while (!q.empty()) { 
        int size = q.size(); 
        
        for (int i=0; i<size; i++) { 
            auto [x,y] = q.front(); 
            q.pop_front(); 
            
            if (x == n-1 && y == m-1) {
                return answer; 
            } // 종료 조건
            
            for (auto &dir : directions) { // 이동 
                int nx = x + dir[0]; 
                int ny = y + dir[1]; 
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push_back({nx, ny});
                    visited[nx][ny] = true;
                }
            } 
        }
        answer++;
    }
    
    return -1;
}