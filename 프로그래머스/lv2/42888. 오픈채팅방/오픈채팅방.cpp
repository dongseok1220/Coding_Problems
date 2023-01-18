#include <string>
#include <vector>
#include <map> 
#include <iostream> 

using namespace std;

struct privacy {
    string name; 
    string id;
    char state;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<privacy> arr; 
    map<string,string> p; 

    int len = record.size(); 

    string delimiter = " "; 
    
    for (int i=0; i<len; i++) {
        size_t pos = 0; 
        int cnt = 0; 
        privacy tmp; 
        record[i].insert(record[i].length(), " ");
        while ((pos = record[i].find(delimiter)) != string::npos) { // 문자열 파싱 
            string str = record[i].substr(0,pos);
            if (cnt == 0) tmp.state = str[0];
            else if (cnt == 1) tmp.id = str;
            else tmp.name = str; 
            record[i].erase(0,pos + 1);
            cnt++;
        }
        if (tmp.state != 'L')  p[tmp.id] = tmp.name;
        if (tmp.state != 'C') {
            arr.push_back(tmp);
        }
    }
    for (auto &s : arr) {
        string v; 
        if (s.state == 'E') v = p[s.id] + "님이 들어왔습니다."; 
        else v = p[s.id] + "님이 나갔습니다.";
        answer.push_back(v); 
    }
    return answer;
}