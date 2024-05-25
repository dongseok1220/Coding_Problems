#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    deque<pair<int, int>> queue; // pair<current_sum, index>
    queue.push_back({0, 0});
    
    while (!queue.empty()) { 
        int cur_sum = queue.front().first; 
        int idx = queue.front().second; 
        
        queue.pop_front(); 
        
        if (idx == numbers.size()) { 
            if (cur_sum == target) answer++; 
        } else {
            queue.push_back({cur_sum + numbers[idx], idx + 1}); 
            queue.push_back({cur_sum - numbers[idx], idx + 1}); 

        }
    }
    return answer;
}