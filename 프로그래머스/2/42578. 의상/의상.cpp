#include <string>
#include <vector>
#include <unordered_map> 
#include <iostream> 

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> clothe; 
    
    for (auto &c : clothes) { 
        clothe[c[1]]++; 
    }
    
    // 총 경우의 수는 각 종류들의 곱 - 1 (전부다 안입는 경우 제외) 
    int temp = 1; 
    for (auto &c : clothe) { 
        temp *= (c.second + 1); 
    }
    answer = temp - 1; 
    
    return answer;
}