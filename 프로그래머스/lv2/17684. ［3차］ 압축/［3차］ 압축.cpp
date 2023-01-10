#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict; 
    
    string alpha = "A";
    for (int i=0; alpha[0] < 'Z'; i++) { 
        alpha[0] = 'A' + i; 
        dict.push_back(alpha);
    }
    
    // for (auto it2 = dict.begin(); it2 != dict.end(); it2++) 
    //     cout << *it2 << " ";
    string w, c; 
    int index;
    int len = msg.length();
    for (int i=0; i<len; ) {
        for (int j=i; j<len; j++) {
            w += msg[j];
            auto it = find(dict.begin(), dict.end(), w);
            if (it == dict.end()) {
                dict.push_back(w);
                break;
            }
            else {
                index = it - dict.begin() + 1;
                i++;
                continue; 
            }
        }
        answer.push_back(index);
        w.clear();
    }
    return answer;
}