#include <string>
#include <vector>
#include <iostream> 

using namespace std;

long long string_to_sec(string time) {
    long long sec[3] = {0, }; 
    long long cur = 0,pos = 0, len = 0;
    
    string seper = ":"; 
    
    int i = 0;
    while ((pos = time.find(seper, cur)) != string::npos) {
        len = pos - cur;
        sec[i] = stoi(time.substr(cur, len));
        cur = pos + 1;
        i++;
    }
    sec[i] = stoi(time.substr(cur, len));
    
    return 3600 * sec[0] + 60 * sec[1] + sec[2]; 
} 

string sec_to_string(long long sec) {
    string tmp = "";
    long long hh = sec / (3600); 
    if (hh < 10 ) tmp += "0" + to_string(hh) + ":"; 
    else tmp += to_string(hh) + ":"; 
    sec = sec % (3600);
    long long  mm = sec / (60);
    if (mm < 10 ) tmp += "0" + to_string(mm) + ":"; 
    else tmp += to_string(mm) + ":"; 
    sec = sec % (60); 
    long long  ss = sec; 
    if (ss < 10 ) tmp += "0" + to_string(ss); 
    else tmp += to_string(ss); 
    
    return tmp; 
}

// 모든 단위를 초로 -> 해설 참조 
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = ""; 
    long long play_time_sec = string_to_sec(play_time); 
    long long adv_time_sec = string_to_sec(adv_time);
    long long max_time = 0; 
    long long total_time[360000] = {0,}; 
 
    for (auto &log : logs) {
        string time1 = log.substr(0, 8); // 시작 시간
        string time2 = log.substr(9, 17); // 종료 시간 
        
        long long t1 = string_to_sec(time1);
        long long t2 = string_to_sec(time2); 
        
        total_time[t1] = total_time[t1] + 1;  // t1초에 시작하는 log들 ++ 
        total_time[t2] = total_time[t2] - 1;  // t2초에 종료되는 log들 --
    }
    
    for (int i=1; i< play_time_sec; i++) { // total_time[i] -> i초와 i-1초에 재생했던 log의 개수 (1초 동안 재생된 log의 개수) 
        total_time[i] = total_time[i] + total_time[i - 1] ;
    }
    for (int i=1; i< play_time_sec; i++) { // total_time[i] -> 0~i초에 재생했던 log들의 누적 재생 시간
        total_time[i] = total_time[i] + total_time[i - 1] ; // 0~(i-1)초동안 재생했던 누적 재생시간 + i초에 1초동안 재생했던 동영상 개수  
    }
    
    // 처음부터 가능한 경우 => 시작지점
    if (max_time < total_time[adv_time_sec - 1] ) {
        max_time = total_time[adv_time_sec - 1];
        answer = sec_to_string(0);
    }
    // 1 ~ adv_time_sec 검사 ...
    for (int i= adv_time_sec; i < play_time_sec; i++) {
        // 만약 현재 max_time 보다 구간합 i - adv_time_sec ~ i 까지가 누적 time이 많을 때 answer를 바꿔줌 
        if (max_time < total_time[i] - total_time[i-adv_time_sec] ) {
            max_time = total_time[i] - total_time[i-adv_time_sec] ;
            answer = sec_to_string(i - adv_time_sec +1);
        }
    }

    return answer;
}