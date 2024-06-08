#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> combination; 

int backtracking(int k, int depth) { 
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            cout << combination[i] << " ";
        }
        cout << endl;
        return 1;
    } else {
        for (int i = k; i <= N; ++i) {
            combination.push_back(i);
            backtracking(i + 1, depth + 1);
            combination.pop_back(); // Backtrack
        }
    }
    return 0;
}

int main() {
    cin >> N >> M;
    backtracking(1, 0);

    return 0;
}
