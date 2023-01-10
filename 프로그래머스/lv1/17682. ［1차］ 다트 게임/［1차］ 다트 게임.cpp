#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0, i = 0; 
    int cur = 0, pre =0; 
    while (dartResult[i]) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            cout << pre << " " << cur << endl;
            pre = cur; 
            if (dartResult[i+1] == '0') {
                cur = 10; 
                i++;
            }
            else cur = dartResult[i] - '0'; 
        }
        else if (dartResult[i] == 'S') {
            cur = cur;
            answer += cur;
        }
        else if (dartResult[i] == 'D') {
            cur = cur * cur; 
            answer += cur; 
        }
        else if (dartResult[i] == 'T') {
            cur = cur * cur * cur;
            answer += cur; 
        }
        else if (dartResult[i] == '*') {
            answer += cur + pre; 
            cur = cur * 2;
        }
        else if (dartResult[i] == '#') {
            cur = -cur; 
            answer += 2*cur; 
        }
        i++; 
    }
    

    return answer;
}