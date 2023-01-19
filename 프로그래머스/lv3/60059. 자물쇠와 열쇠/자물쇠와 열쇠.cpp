#include <string>
#include <vector>
#include <algorithm> 
#include <iostream> 
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int N = lock.size(); 
    int M = key.size(); 
    int flag = 0; 
    
    vector<pair<int,int>> l_loc,tmp_loc, ban; 
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) 
            if (lock[i][j] == 0) l_loc.push_back(make_pair(i,j));
            else ban.push_back(make_pair(i,j));
    }
   
    for (int i=0; i< M; i++) {
        for (int j=0; j<M; j++) 
            if (key[i][j] == 1) tmp_loc.push_back(make_pair(i,j));
    }
    cout << (find(ban.begin(), ban.end(), make_pair(2,2)) == ban.end()); 
    for (int rotate = 0; rotate <4; rotate++) { // 회전 시킬 회수 
        switch (rotate) {
            case 0 :
                break;
            default :
                for (auto &k : tmp_loc) {
                    int tmp = k.second; 
                    k.second = M - k.first - 1;
                    k.first = tmp;   
                }
        }    
        vector<pair<int,int>> k_loc; 
        for (auto &k : tmp_loc) 
            k_loc.push_back(k);
        
        // 회전시킨 key의 위치를 상하좌우로 한칸씩 움직여본다.
        // 매 경우마다 loc의 위치와 비교한다. 
        // loc과 모두 일치하고 일치 하지 않는 키가 N의 범위 밖에 있을 경우 true를 반환한다. 
        
        // 처음 키의 위치를 모든 키가 -가 될 때 까지 옮김 
        int flag = 1; 
        while (flag) {
            flag = 0; 
            for (auto &k : k_loc) {
                k.first--;
                k.second--; 
                if (k.first > 0 || k.second > 0) {
                    flag = 1;
                }
            }
        }
        
        for (int m=0; m<2*N; m++) {  
            for (int t=0; t<2*N; t++) { // 오른쪽으로 t만큼 움직임
                flag = 0;
                for (auto &l : l_loc) {
                    for (auto &k : k_loc) {
                        if (find(ban.begin(), ban.end(), make_pair(k.first,k.second+t)) != ban.end()) break;
                        if (k.first == l.first && k.second + t == l.second) {
                            flag++;
                            break;
                        }
                        if (k.first != k.first >= N || k.second + t >= N || k.first < 0 || k.second + t < 0) continue;
                        // 돌기와 만날 때 검사 
                    }
                }
                
                if (flag == l_loc.size()) return true; 
            }
            for (auto &k : k_loc) 
                k.first ++; // 아래로 m만큼 내림    
        }
    }
    // cout << "자물쇠 위치" << endl;
    // for (auto &s : l_loc)
    //     cout << s.first << " " << s.second << endl;
    
    
    return answer;
}