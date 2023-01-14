#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;


int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();     
    int col = relation[0].size();
    // 1. 모두 다를 경우 후보키가 된다. 
    // 2. 두 개 이상의 속성을 합쳐 보았을 때 후보키가 된다. 이때, 유일성을 만족하는 속성은 포함하면 안된다. 
    // 3. 또한, 이때 최소성을 만족해야한다. 어떤 속성 하나가 빠질 경우 유일식별이 불가능함을 말함 
    // 중복이 있어도 다른 속성에서 다른 값을 가진다면 두 속성은 후보키가 될 수 있다. 
    
    
    vector<int> index; 
    vector<vector<int>> ans; 
    
    bool flag; // 유일성을 확인하는 변수 
    int check;
    
    for (int i=0; i<col; i++) { // 속성을 보는 반복문 
        check = row; 
        vector<string> v; // 임시 변수
        for (int j=0; j<row; j++) { // 각 튜플을 검사하는 반복문 
            v.push_back(relation[j][i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()),v.end());
    
        if (check == v.size()) {
            answer++;
            vector<int> k; 
            k.push_back(i);
            ans.push_back(k); 
        }
        else {
            index.push_back(i);
        }
    }
    int size = index.size(), i, j, t;
    // 여기서 조합 찾아야함 최소 2개부터 ~ 
    // next_permutation 사용 

    for (i = 2; i<=size; i++) {
        vector<int> visit; // 조합을 위한 배열 
        for (j=size; j>0; j--) {
            if (j>i) visit.push_back(0);
            else visit.push_back(1); 
        }
      
        // 조합 index 찾기 
        vector<int> ind; 
        do {
            flag = false; 
            for (t=0; t < size; t++) 
                if (visit[t] != 0) ind.push_back(index[t]); 
            sort(ind.begin(),ind.end());
            
            // cout << "정답 : " ;
            // for (t=0; t<ans.size(); t++) {
            //     for (j=0; j<ans[t].size(); j++) 
            //         cout << ans[t][j] << " ";
            //     cout << "," ;
            // }
            // cout << "현재 :" ;
            // for (t=0; t<ind.size(); t++) {
            //     cout << ind[t] << " ";
            // }
            // cout << endl; 
            
            for (j=0; j <ans.size(); j++) {
                vector<int> result(size); 
                
                auto iter = set_difference(ans[j].begin(),ans[j].end(),ind.begin(), ind.end(), result.begin());
                result.resize(iter - result.begin()); 
                if (result.size() == 0) {
                    flag = true; 
                } 
            }
            if (flag == true) {
                ind.clear();
                continue;
            } 
            
            vector<vector<string>> tmp; 
            vector<string> str; // 임시 변수 
            
            for (j=0; j<row; j++) {
                for (t=0; t<ind.size(); t++) 
                   str.push_back(relation[j][ind[t]]);  
                tmp.push_back(str);
                str.clear();
            }
            check = row; 
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()),tmp.end());
            
            if (check == tmp.size()) {
                ans.push_back(ind); 
                answer++; 
            }
            ind.clear(); 
        } while (next_permutation(visit.begin(), visit.end()));
    }
    
    if (answer == 0) answer++; 
    
    return answer;
}