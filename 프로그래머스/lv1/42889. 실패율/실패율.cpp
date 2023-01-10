#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;

struct stage {
    int fail; 
    int done;
    int index;
    double per; 
};

bool comp(stage a, stage b) {
    if (a.per > b.per ) return true;
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // 실패율 = 도전 / 도달 
    int num = stages.size(); // 총 사용자 수 
    double total; 
    stage *arr = new stage[N+1];
    for (int i=0; i<=N; i++)
    {
        arr[i].index = i; 
        arr[i].fail = 0;
        arr[i].done = 0; 
        arr[i].per = 0;
    }
    
    for (int i=0; i<num; i++) { 
        int end = stages[i]; 

        for (int j=1; j<end; j++) {
            arr[j].done++;
        }
        if (end != N+1) arr[end].fail++; 
    }
    
    for (int i=1; i<=N; i++){
        total = arr[i].fail + arr[i].done; 
        if (total == 0) continue;
        arr[i].per = (total - arr[i].done) / total; 
    }
    
    stable_sort(arr+1,arr+N+1,comp);
    
    for (int i=1; i<=N; i++){
        //cout << arr[i].per << " ";
        answer.push_back(arr[i].index);
    }
    delete []arr;
    return answer;
}