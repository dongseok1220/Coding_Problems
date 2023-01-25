#include <string>
#include <vector>
#include <unordered_map> 

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
        int step = count / 2;
        int it = start + step; 
        if (comp(str,words[it])) {
            count = step;
        }
        else { 
            start = ++it; 
            count -= step + 1; 
        }
    }
    return start; 
}

int search_upperbound(vector<string> words, string str, int start, int end) {
    int count = end - start; 

    while (count > 0) {
        int step = count / 2;
        int it = start + step; 
        
        if (!comp(str,words[it])) {
            start = ++it;
            count -= step + 1;
        }
        else count = step;
    } 
    return start; 
}

bool match(string &query, string &word) {
    if (query.length() != word.length()) {
        return false;
    }

    for (int i = 0; i < query.length(); ++i) {
        if (query[i] != '?' && query[i] != word[i]) {
            return false;
        }
    }

    return true;
}
// 직접 이분탐색을 구현하면 시간초과난다. 이유가 뭘까. 
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer; 
    int max_length = 0; 
    for (string &word : words) {
        max_length = max_length > word.length() ? max_length : word.length();
    }
    
    if (max_length > 1000) {
        for (string &query : queries) {
            int num_matched = 0;

            for (string &word : words) {
                if (match(query, word)) {
                    num_matched++;
                }
            }

            answer.push_back(num_matched);
        }
    }
    else {
        unordered_map<string, int> quer; 
        for (auto &s : queries) quer[s] = 0; 
    
        for (auto &word : words) {
            string tmp = word; 
            for (int i=0; i<word.length(); i++) {
                tmp[i] = '?'; 
                if (quer.find(tmp) != quer.end()) quer[tmp]++;
            }
            for (int i=word.length()-1; i > 0; i--) {
                word[i] = '?'; 
                if (quer.find(word) != quer.end()) quer[word]++;
            }
        }
        for (auto &q : queries) {
            answer.push_back(quer[q]);
        }
    }
    return answer;
}