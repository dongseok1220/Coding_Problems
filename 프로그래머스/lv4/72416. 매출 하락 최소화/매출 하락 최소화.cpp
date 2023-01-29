#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unordered_map> 
#define MIN(a,b) { a < b ? a : b }

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    int len = sales.size(); 
    
    //자력으로 풀이 X 
    
    int **DP = new int*[len+1] {0,}; 
    for (int i=0; i<=len; i++)
        DP[i] = new int[2] {0,}; // DP[i][0]은 팀장이 참석 X, DP[i][1]은 팀장이 참석 O 
    
    sort(links.begin(), links.end()); 

    vector<int> visit(len+1), child(len+1), sum_child(len+1), check(len+1);
    fill(visit.begin(), visit.end(), 0); // 방문 여부 DFS를 위한 벡터 
    fill(child.begin(), child.end(), 0); // 자식노드의 유무
    fill(sum_child.begin(), sum_child.end(), 0); // 계산을 위한 벡터 
    fill(check.begin(), check.end(), 0);
    
    vector<int> t; // 현재 방문중인 노드를 위한 벡터 
    t.push_back(1); 
    
    unordered_map<int, vector<int>> link; 
    for (auto &l : links) {
        link[l[0]].push_back(l[1]);
    }
    
    while(t.size() >= 1) 
    {
//         cout << "현재 방문 순서" << endl;
//         for (auto &s : t) 
//             cout << s << " ";
//         cout << endl;
        
//         cout << "현재 저장되는 값" << endl;
//         for (int i=1; i<=len; i++) {
//             for (int j=0; j<=1; j++) {
//                 cout << DP[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        int flag = 0; 
        int cur = t.back(); // 현재 노드 
        for (auto &l : link[cur]) {
            if (visit[l] != 1) {
                child[cur] = 1; // 자식이 있음
                t.push_back(l);
                visit[l] = 1; 
                flag = 1; 
                break;
            }
        }
    
        if (flag == 0 ) {
            int i = t.back();
            DP[i][1] = sales[i-1] + sum_child[i];
            if (check[i] == -1) {
                DP[i][0] = sum_child[i];
            }     
            else {
                DP[i][0] = check[i] + sum_child[i];
            }
            t.pop_back(); 
            int p = t.back(); 
        
            sum_child[p] += MIN(DP[i][0], DP[i][1]); 
            
            if (DP[i][0] < DP[i][1]) {
                if (check[p] == -1) continue;
                else if (check[p] == 0) check[p] = DP[i][1] - DP[i][0];
                else check[p] = MIN(DP[i][1] - DP[i][0], check[p]); 
            }
            else check[p] = - 1; 
            if (i==1) break;
        }
    }
    
    answer = MIN(DP[1][0], DP[1][1]);
    
    for (int i=0; i<=len; i++)
        delete[] DP[i]; 
    delete[] DP; 
    
    return answer;
}