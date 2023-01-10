#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 

using namespace std;

struct tmp {
    int hour;
    int minute; 
};

bool comp(tmp a, tmp b) {
    if (a.hour < b.hour) return a.hour < b.hour;
    else if (a.hour == b.hour ) {
        if (a.minute < b.minute) return a.minute < b.minute; 
        else return b.minute > a.minute; 
    }
    else return b.hour > a.hour; 
}

string make(tmp a) {
    string ans;
    string str1, str2; 
    if (a.hour < 10) {
        str1 = "0" + to_string(a.hour);
    }
    else str1 = to_string(a.hour);
    if (a.minute < 10) {
        str2 = "0" + to_string(a.minute);
    }
    else str2 = to_string(a.minute);
    
    ans = str1 + ":" + str2; 
    return ans;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int num = timetable.size(); 
    
    tmp first; 
    first.hour = 9; 
    first.minute = 0; 
    
    tmp *arr = new tmp[num];
    
    for (int i =0; i<num; i++) {
        arr[i].hour = (timetable[i][0] - '0')*10 + timetable[i][1] - '0';
        arr[i].minute = (timetable[i][3] - '0')*10 + timetable[i][4] - '0';
        if (arr[i].hour == 24) {
            arr[i].hour = 0;
            arr[i].minute = 0;
        }
    }
    
    sort(arr, arr+num,comp);
    
    for (int i=0; i<num; i++) {
        cout << arr[i].hour << " " << arr[i].minute << endl;
    }
    tmp cur; 
    cur.hour = 9;
    cur.minute = 0;
    
    int cnt = 0;
    int res = 0;
    int i;
    
    while (n > 0 && num + 1 > cnt) {
        for (i = cnt; i<num; i++) {
            if (arr[i].hour < cur.hour) res++;
            if (arr[i].hour == cur.hour && arr[i].minute <= cur.minute) res++;
            if (n == 1 && res == m) break; 
            if (n > 1 && res == m) break;
        }
        cnt += res; 
        if (n==1) { 
            if (res == m) {
                arr[i].minute -= 1; 
                if (arr[i].minute < 0) {
                    arr[i].minute = 59;
                    arr[i].hour -= 1; 
                }
                answer = make(arr[i]);
            }
            else answer = make(cur);
        }
        
        n--;    
        res = 0;
        cur.minute += t; 
        if (cur.minute >= 60) {
            cur.minute -= 60; 
            cur.hour += 1; 
        }
    }
    delete []arr;
    
    return answer;
}