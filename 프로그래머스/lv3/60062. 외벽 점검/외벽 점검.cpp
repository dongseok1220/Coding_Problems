#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int len_weak = weak.size(); 
    int len_dist = dist.size();
    int answer = len_dist + 1; 
    // 직선변경 -> 시계방향으로 이동만 고려함 
    for (int i=0; i< len_weak - 1; i++) {
        weak.push_back(n + weak[i]);
    }
    
    int i,j,k;
    do {
        for (int start = 0; start < weak.size() - len_weak; start++) { 
            k = 0;
            int can_move = dist[k];
            for (i=start; i < start + len_weak - 1 ; i++) {
                int dis = weak[i+1] - weak[i];
                if (can_move - dis >= 0) {
                    can_move -= dis; 
                }
                else {
                    k++;
                    can_move = dist[k];
                }
            }
            if (answer > k + 1 && i == start + len_weak - 1) answer = k + 1; 
        }
    } while (next_permutation(dist.begin(), dist.end()));

    if (answer == len_dist +1) return -1;
    
    return answer;
}