#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 
#include <unordered_map> 
#include <map>

using namespace std;

bool comp(string a, string b) {
    if (a.length() > b.length())
        return false;
    else if (a.length() == b.length()) return a < b; 
    else return true; 
}

int search_lowerbound(vector<string> words, string str,int start, int end) {
    int count = end - start; 
    while (count > 0) {
        int it = start; 
        int step = count / 2;
        it += step; 
        if (comp(str,words[it])) {
            count = step;
        }
        else { 
            start = ++it; 
            count -= step + 1; 
        }
        // else if (words[mid].length() == len) { // 만약 길이가 같다면 사전으로 비교함! 
        //     if (words[mid] < str) { // 사전상 str이 더 크다면 오른쪽
        //         start = mid + 1;
        //     }
        //     else { // 더 작다면 
        //         end = mid; 
        //     }
        // }
    }
    return start; 
}

int search_upperbound(vector<string> words, string str, int start, int end) {
    int count = end - start; 

    while (count > 0) {
        int it = start;
        int step = count / 2;
        it += step; 
        
        if (!comp(str,words[it])) {
            start = ++it;
            count -= step + 1;
        }
        else count = step;
        // else if (words[mid].length() == len) { // 만약 길이가 같다면 사전으로 비교함! 
        //     if (words[mid] <= str) { // 이번에는 가능하면서 가장 큰 인덱스를 찾아야하므로 
        //         start = mid + 1;
        //     }
        //     else { // 더 작다면 
        //         end = mid; 
        //     }
        // }
    } 
    return start; 
}

// 시간초과 이유 -> 모든 words를 탐색하기 때문 -> 길이 별로 나눈 배열만 돌도록 하자! -> 근데도 시간초과..
vector<int> solution(vector<string> words, vector<string> queries) {
//     int len = words.size();
//     vector<int> answer(queries.size()); 
    
//     vector<string> rwords(words); // ?로 시작하는 단어들을 reverse 시킨 후 정렬을 할 필요가 있음!! 
    
//     for (int i = 0; i < rwords.size(); i++) 
//         reverse(rwords[i].begin(), rwords[i].end());
    
//     vector<pair<string, int>> arr; 
//     for (int i=0; i<queries.size(); i++) {
//         arr.push_back(make_pair(queries[i],i));
//     }
    
//     sort(arr.begin(), arr.end()); 
//     sort(rwords.begin(), rwords.end(), comp);
//     sort(words.begin(), words.end(), comp); 
    
//     int pre = words[0].length(); 
//     typedef pair<int,int> index;
//     unordered_map<int,index> size_set; 
//     int s = 0,e = 0; 
    
//     for (int i=1; i<len; i++) {
//         if (pre != words[i].length()) {
//             e = i; 
//             size_set[pre] = make_pair(s,e);
//             s = i; 
//         }
//         pre = words[i].length(); 
//     }
//     size_set[pre] = make_pair(s,len);
//     // 문제 특성상 같은 길이에 대해서 생각해야한다! 따라서, comp함수로 같은 길이에 대해서 사전순 정렬을 시키도록 함 
    
//     string overlap = ""; 
//     int start = 0, end =0; 
//     int low = 0, high = len; 
    
//     for (auto &s : arr) { // queries를 순회하면서 이분탐색 활용.. 
//         string q = s.first; 
//         int size = q.length(); 
        
//         low = size_set[size].first;
//         high = size_set[size].second; 
     
//         if (q[0] == '?') { // ?로 시작할 경우 거꾸로 만든 후 rwords를 통해 탐색을 진행한다! 
//             reverse(q.begin(), q.end());
//             start = search_lowerbound(rwords, q, low, high);
//             for (int i=size - 1; i >= 0; i--) 
//                 if (q[i] == '?') q[i] = 'z';
//                 else break;
//             end = search_upperbound(rwords, q, low, high);
//             // auto start = lower_bound(rwords.begin(), rwords.end(), q, comp);  
//             // auto end = upper_bound(rwords.begin(), rwords.end(), q, comp);
//             answer[s.second] = end-start; 
//         }
//         else { // ?로 끝날 경우 
//             start = search_lowerbound(words, q, low, high);
//             for (int i=size-1; i>=0; i--) 
//                 if (q[i] == '?') q[i] = 'z';
//                 else break;
//             end = search_upperbound(words, q, low, high);
//             // auto start = lower_bound(words.begin(), words.end(), q, comp); 
//             // auto end = upper_bound(words.begin(), words.end(), q, comp);
//             answer[s.second] = end-start; 
//         }
//         overlap = q; 
//     }
    vector<int> answer; 
    map<string,int> m;
    for(string& s:queries)m[s]=0;

    for(string& s:words){
        string pre=s;
        for(int i=0;i<pre.length();++i){
            pre[i]='?';
            if(m.find(pre)!=m.end())m[pre]++;
        }
        pre=s;
        for(int i=pre.length();i>0;--i){
            pre[i]='?';
            if(m.find(pre)!=m.end())m[pre]++;
        }
    }

    for(string& s:queries)answer.push_back(m[s]);
    
    return answer;
}