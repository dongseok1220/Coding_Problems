#include <string>
#include <vector>
#include <deque> 

using namespace std;

void DFS(int start, vector<vector<int>> &computers, vector<bool> & visited) { 
    deque<int> stack; 
    
    stack.push_back(start); 
    
    while (!stack.empty()) {
        int node = stack.back(); 
        stack.pop_back(); 
        
        if (!visited[node]) {
            visited[node] = true; 
            for (int i = 0; i < computers.size(); i++) {
                if (computers[node][i] == 1 && !visited[i]) {
                    stack.push_back(i); 
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false); 
    
    for (int i=0; i<n; i++) { 
        if (!visited[i]) { 
            DFS(i, computers, visited); 
            answer++; 
        }
    }
    
    return answer;
}