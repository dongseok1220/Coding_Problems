#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;

vector<pair<int,int>> Pillar,Paper; // 각 기둥과 보의 x,y 좌표 

bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        if (a[1] == b[1]) return (a[2] == 0); 
        else if (a[1] > b[1]) return false; 
    }
    else if (a[0] > b[0]) return false; 
    
    return true; 
}

int ismake (int x, int y, int build) {
    if (build) { // 보
        if (find(Pillar.begin(), Pillar.end(), make_pair(x,y-1)) != Pillar.end() ) { 
            return 1;
        }
        else if (find(Pillar.begin(), Pillar.end(), make_pair(x+1,y-1)) != Pillar.end()) { 
            return 1;
        }
        else if ((find(Paper.begin(), Paper.end(), make_pair(x-1,y)) != Paper.end()) && (find(Paper.begin(), Paper.end(), make_pair(x+1,y)) != Paper.end())) {
            return 1;
        }

    }
    else { // 기둥
        if (y == 0) { // 바닥에 설치하는 경우 
            return 2;
        }
        else if (find(Paper.begin(), Paper.end(), make_pair(x,y)) != Paper.end()) { 
           return 2;
        }
        else if (find(Paper.begin(), Paper.end(), make_pair(x-1,y)) != Paper.end()) { 
            return 2; 
        }
        else if (find(Pillar.begin(), Pillar.end(), make_pair(x,y-1)) != Pillar.end()) { 
            return 2; 
        }
    }
    
    return 0; 
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for (int i=0; i< build_frame.size(); i++) {
        int x = build_frame[i][0]; 
        int y = build_frame[i][1]; 
        int build = build_frame[i][2]; // 0이면 기둥 , 1이면 보
        int state = build_frame[i][3]; // 0이면 삭제, 1이면 설치
        
        vector<int> arr(3);
        arr[0] = x, arr[1] = y, arr[2] = build; 
         
        if (state) { // 설치 
            if (ismake(x,y,build) == 2) { 
                answer.push_back(arr);
                Pillar.push_back(make_pair(x,y));
            }
            else if (ismake(x,y,build) == 1) {
                answer.push_back(arr);
                Paper.push_back(make_pair(x,y));
            }
        }
        else { // 삭제
            answer.erase(find(answer.begin(),answer.end(),arr));
            if (build == 0) Pillar.erase(find(Pillar.begin(), Pillar.end(), make_pair(x,y)));
            else Paper.erase(find(Paper.begin(), Paper.end(), make_pair(x,y)));
            
//             cout << "PAPER" << endl;
//             for (auto &p : Paper) {
//                 cout << p.first << " " << p.second << endl; 
//             }
            
            bool flag = true;
            for (auto &s : answer) {
                //cout << i << " : " << s[0] << " " << s[1] << " " << s[2] << endl;
                if (ismake(s[0],s[1],s[2])) continue; 
                else {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                answer.push_back(arr);
                if (build == 0) Pillar.push_back(make_pair(x,y));
                else Paper.push_back(make_pair(x,y));
            }
        }
        sort(answer.begin(), answer.end(), comp);
        
    }

    return answer;
}