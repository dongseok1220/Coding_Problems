#include <iostream> 
#include <vector>
#include <deque>
#include <map> 
#include <utility>

using namespace std; 

int main() {
    string notation; 
    cin >> notation; 

    deque<pair<char, int>> oper; 
    map<char, int> prior; 


    prior['*'] = 2;
    prior['/'] = 2; 
    prior['+'] = 1; 
    prior['-'] = 1; 

    int flag = 0; 
    for (auto &n : notation ) {
        if (n == '(') {
            flag += 3; 
            continue;
        }
        if (n == ')') {
            flag -= 3;
            continue; 
        }
        if (n >= 'A' && n <= 'Z') cout << n; // 피연산자의 순서는 영향 x 
        else {
            while(!oper.empty()) {
                char cur = oper.front().first;
                int p = oper.front().second; 
                 if (p >= prior[n] + flag) {
                    cout << cur;
                 }  else break;
                oper.pop_front(); 
            }
            oper.push_front({n, prior[n]+ flag});
        }
    }

    while(!oper.empty()) {
        cout << oper.front().first; 
        oper.pop_front(); 
    }
    return 0; 
}