#include <string>
#include <vector>
#include <unordered_map> 

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m; 
    string answer = "";
    
    for (auto &c : completion) {
        m[c]++; 
    }
    
    for (auto &p : participant) {
        m[p]--;
        if (m[p] < 0) return p; 
    }
}