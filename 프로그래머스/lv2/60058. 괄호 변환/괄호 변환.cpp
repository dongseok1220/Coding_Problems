#include <string>
#include <vector>
#include <iostream> 

using namespace std;

string make_par(string target) {
    if (target == "") return "";
    string u = "";
    string v = "";
    int l = 0,r = 0; 
    int check = 0;
    bool correct = true; 
    
    for (int i=0; i<target.length(); i++) {
        if (target[i] == '(') {
            l++;
            check++; 
        }
        else if (target[i] == ')') {
            if (check == 0) correct = false; 
            else check--; 
            r++; 
        }
        if (l == r) {
            u = target.substr(0,i+1); 
            v = target.substr(i+1); 
            //cout << endl << u << " " << v << endl;
            if (correct) {
                u += make_par(v);
                return u; 
            }
            else {
                string tmp = "(" + make_par(v) + ")";
                for (int j=1; j<u.length()-1; j++) {
                    if (u[j] == '(') tmp += ")"; 
                    else tmp += "("; 
                }
                return tmp; 
            }
            break;
        }
    }
}

string solution(string p) {
    string answer = "";
    int len = answer.length();
    int l_par, r_par, i = 0; 
    string u = "";
    string v = "";
    int flag = 0; // 0이면 u에 1이면 v에 
    
    answer = make_par(p); 
    
    return answer;
}