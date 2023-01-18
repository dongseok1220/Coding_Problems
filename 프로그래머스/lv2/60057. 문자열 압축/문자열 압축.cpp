#include <string>
#include <vector>
#include <iostream> 

using namespace std;

int solution(string s) {
    int answer = 1001;
    int len = 1; // 자를 단위 
    int press_len; 

    for (; ;) {
        string cur = s.substr(0,len);
        press_len = cur.length(); 
        int cnt =1; 
        
        for (int i=len; i<s.length(); i += len) {
            if (cur == s.substr(i,len)) {
                cnt++;
                continue;
            }
            else {
                if (cnt >= 10) press_len += 2; 
                else if (cnt < 10 && cnt > 1) press_len++;
                cur = s.substr(i,len);
                press_len += cur.length(); // 다르면 그 길이만큼 추가 
                cnt = 1;
            }
        }
        if (cnt >= 10) press_len += 2; 
        else if (cnt < 10 && cnt > 1) press_len++;
        
        //cout << endl << len << " 단위로 압축 : " <<  press_len << endl; 
        
        if (press_len < answer) answer = press_len; 
        len++; 
        if (2 * len > s.length()) break; // 자를 단위가 절반이상이 되면 break;
    }
    
    
    return answer;
}