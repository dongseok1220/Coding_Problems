#include <string>
#include <vector>
#include <iostream> 

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int cnt;
    int len = lines.size();
    
    string date, p_time; 
    int hh, mm;
    double p, ss; 
    vector<double> start, end; 
    cout << fixed; 
    cout.precision(4); 
    
    for (int i=0; i<len; i++) {
        date = lines[i].substr(11,12); 
        p_time = lines[i].substr(24); 

        p = stod(p_time);
        hh = stoi(date.substr(0,2));
        mm = stoi(date.substr(3,2));
        ss = stod(date.substr(6));
        double s = 3600 * hh + 60 * mm + ss - p + 0.001; 
        double e = 3600 * hh + 60 *mm + ss; 
        //cout << s << " " << e << endl; 
        start.push_back(s);
        end.push_back(e);
    }
    for (int i=0; i<len; i++) {
        cnt = 0; 
        for (int j=i; j<len; j++) {
            if (start[j] < end[i] + 1) cnt++; 
        }
        if (answer < cnt) answer = cnt; 
    }
    
    return answer;
}