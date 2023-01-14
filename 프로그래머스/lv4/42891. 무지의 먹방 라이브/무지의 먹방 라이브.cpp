#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1;   
    long long len = food_times.size();
    
    vector<int> arr(len); 
    vector<pair<int, int>> ans; 
    
    copy(food_times.begin(), food_times.end(), arr.begin());
    
    for (int i=0; i<len; i++)
        ans.push_back(make_pair(food_times[i], i));
    
    sort(ans.begin(), ans.end()); 
    
    long long sum = 0;
    long long min = 0, index = 0,cur = 0, i=0;
    long long cnt = len; 
    long long acc = 0; // 누적 변수 
    
    while(k >= cnt) {
        if (index >= len) return -1; // 모든 음식 다 먹을 경우 
        
        // for (i=0; i<len; i++) 
        //     cout << ans[i].first << " ";
        // cout << endl; 
        
        min = ans[index].first - acc; // 현재 배열
        
        sum = min*cnt; // 최소 값 * 0이 아닌 원소 개수 
        
        if (k < sum) { // 반복할 수 없다 -> k를 개수로 나눈 나머지 , min 은 k를 개수로 나눈 몫
            min = k / cnt; 
            k = k % cnt;         
        }
        else k -= sum; // 반복 가능 -> -해준다. 
        
        acc += min;
        //cout << "최소 : " << min << " 누적 : " << acc << " 시간 : " << k << endl; 
        
        ans[index].first -= acc ; // min만큼 빼줌 
        if (ans[index].first > 0) {
            continue;
        }
        index++;
        cnt--;
        for (i=index; i<len; i++) {
            if (ans[i].first - acc == 0 ) {
                ans[i].first -= acc;
                index++;
                cnt--;
            }
            else break; 
        }
    } 
    //cout << "최소 : " << min << " 누적 : " << acc << " 시간 : " << k << endl; 
    vector<int> s; 
    for (i=index; i<len; i++) {
        s.push_back(ans[i].second); 
    } 
    sort(s.begin(),s.end());
    answer = s[k] + 1; 
    
    return answer;
}
