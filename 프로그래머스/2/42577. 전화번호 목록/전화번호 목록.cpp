#include <string>
#include <vector>
#include <unordered_map> 
#include <algorithm> 

using namespace std;

bool comp(const string &a, const string &b) {
    return a.size() < b.size(); 
}

bool solution(vector<string> phone_book) {
    unordered_map<string, int> phone; 
    
    sort(phone_book.begin(), phone_book.end(), comp);

    bool answer = true;
    
    for (auto &p: phone_book) { 
        string temp = ""; 
        for (auto &c : p) {
            temp += c;
            if (phone[temp] == 1) return false; 
        }
        phone[p] = 1; 
    }
    
    return answer;
}