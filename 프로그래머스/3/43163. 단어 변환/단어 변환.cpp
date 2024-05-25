#include <string>
#include <vector>
#include <deque> 

using namespace std;

bool comp(string a, string b) { // string에서 알파벳 차이 확인
    int cnt = 0; 
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue; 
        else cnt++; 
        if (cnt > 1) return false; 
    }
    return true; 
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size(); 
    vector<bool> visited(n, false); 
    
    deque<string> q; // bfs -> 알파벳 하나 차이나면 모두 방문 
    
    q.push_back(begin); 
    
    while (!q.empty()) {
        for (int j=0; j < q.size(); j++) {
            string cur = q.front();
            if (cur == target) return answer;
            q.pop_front(); 
            for (int i = 0; i < n; i++) {
                if (comp(cur, words[i]) && !visited[i]) {
                    q.push_back(words[i]);
                    visited[i] = true; 
                }
            }
        }
        answer++; 
    }
    
    return 0;
}