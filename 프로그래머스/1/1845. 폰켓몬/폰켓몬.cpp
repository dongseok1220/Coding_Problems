#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    unordered_map<int, int> m;
    for (auto &p : nums) { 
        if (m[p] == 0) { 
            m[p] = 1; 
            answer++;
            if (answer >= N/2) break; 
        }
    }
    
    return answer;
}