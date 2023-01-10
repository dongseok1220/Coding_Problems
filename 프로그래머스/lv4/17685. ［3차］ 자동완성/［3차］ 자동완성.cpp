#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

// bool comp(string a, string b) {
//     if (a.length() > b.length()) return false;
//     else return true; 
// }

int solution(vector<string> words) {
    int answer = 0;
    char word; 
    int flag, len; 
    int size = words.size();
    
    int *dp = new int[size];
    for (int i=0; i<size; i++)
        dp[i] = 1; 
    
    if (size == 1) return 1; 
    sort(words.begin(), words.end());
    
    for (int i=0; i<size; i++) {
        len = words[i].length();
        
        for (int j=dp[i]; j <= len; j++) {
            word = words[i][j-1];
            //cout << i << " " << j << " 이 단어가 있냐? "<< word << endl;
            flag = 0;
            for (int k = i+1; k < size; k++) {
                if (dp[k] != dp[i] || words[k][j-1] != word ) continue; 
                else {
                    if (dp[k] < words[k].size()) dp[k]++;
                    flag = 1; 
                    //cout << k << " 있다" << endl;
                }
            }
            if (flag == 0) break;
            if (j != len) dp[i]++;
            // for (int c=0; c<size;c++)
            //     cout << dp[c] << " ";
            // cout << endl;
        }
    }
    
    for (int c=0; c < size; c++)
        answer += dp[c]; 
    
    delete[] dp; 
    
    return answer;
}