#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[51];

int find(int x) {
    if (parent[x] == x) return x; 
    else return parent[x] = find(parent[x]); 
}

void union_sets(int a, int b) { 
    a = find(a); // 부모 찾기 
    b = find(b); 
    if (a != b ) parent[b] = a; // 다르면 부모 업데이트 
}

int main() {
    int N, M;
    cin >> N >> M;
    int truthCount;
    cin >> truthCount;
    
    vector<int> truthPeople(truthCount);
    for (int i = 0; i < truthCount; i++) {
        cin >> truthPeople[i];
    }

    vector<vector<int>> parties(M);
    for (int i = 0; i < M; i++) {
        int partySize;
        cin >> partySize;
        parties[i].resize(partySize);
        for (int j = 0; j < partySize; ++j) {
            cin >> parties[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    // 진실을 알고 있는 사람들끼리 묶음
    for (int i = 1; i < truthCount; i++) {
        union_sets(truthPeople[0], truthPeople[i]);
    }
    
    // 동일 파티 사람들끼리 묶음
    for (auto &party : parties) {
        for (int i = 1; i < party.size(); i++) {
            union_sets(party[0], party[i]);
        }
    }

    int truthRoot = truthCount > 0 ? find(truthPeople[0]) : -1;
    int cnt = 0;

    if (truthRoot == -1) {
        cout << M;
        return 0;
    } 

    for (auto &party : parties) { 
        bool flag = true; 
        for (auto &person : party) { 
            if (find(person) == truthRoot) { // 그룹의 root를 결국 찾으면 거짓말 못함 
                flag = false; 
                break; 
            }
        }
        if (flag) cnt++;
    }

    cout << cnt; 

    return 0;
}
