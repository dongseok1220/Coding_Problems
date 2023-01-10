#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

int n_digit(int n, int k, string &str) {
    string digit;
    int cnt = 0;
    if (k == 0) {
        str = "0";
        return 1; 
    }
    while (k > 0) {
        digit[cnt] = k % n + '0'; 
        if (k % n >= 10) {
            digit[cnt] = 'A' + k % n - 10; 
        }
        k = k / n;
        cnt++;
    }
    for (int i=0; i<cnt; i++) {
        str += digit[cnt-i-1]; 
    }
    return cnt; 
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";
    // 순서는 p + m * i 
    int size; 
    int num = 0; 
    int cnt = 1; 
    while(t > 0) {
        size = n_digit(n,num,str);
        for (int i=0; i<size; i++) {
            if (cnt == p) {
                answer += str[i]; 
                p += m; 
                t--;
            }
            if (t == 0) break;
            cnt++;
        }
        str.clear(); 
        num++; 
    }
    
    return answer;
}