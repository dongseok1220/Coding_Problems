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
            // i번째 노드가 참석하면 자식들은 별로 신경 X 
            DP[i][1] = sales[i-1] + sum_child[i]; 
            // 반면 자기 자신이 참석하지 않는다면 2가지 경우가 존재! 
            // 우선, 자기 자식의 노드들 중 한명이라도 sum_child[i]를 계산하는 과정에서 포함되었다면 dp[i][1]은 sum_child[i]가 된다!
            // 하지만, sum_child[i]의 계산과정에서 자기 자식의 노드가 한명도 포함되지 않았다면 자식 노드들 중 가장 MIN값을 찾아 더해주어야 한다! 
            if (check[i] == -1) { 
                DP[i][0] = sum_child[i];
            }     
            else {
                DP[i][0] = check[i] + sum_child[i];
            }
            t.pop_back(); 
            int p = t.back(); 
        
            sum_child[p] += MIN(DP[i][0], DP[i][1]); 
            
            // 부모노드의 자식노드 중 계산 과정에서 한번이라도 DP[i][1] < DP[i][0] 을 만족한다면, 자기 자식의 노드가 적어도 한번은 포함되었다는 얘기다.
            // 따라서, check[p] = -1이라면 DP[i][0] = sum_child[i] 값이 될 것이다. 
            // 반면, 한번이라도 DP[i][0] > DP[i][1] 이 된적이없다면 자식 노드에서 DP[i][1] - DP[i][0] 값 중 가장 작은 값을 넘겨준다. -> 자식 노드 중 최소 값을 의미
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
