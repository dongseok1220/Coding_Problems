#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int distance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int chicken_distance(vector<pair<int, int>>& homes, vector<pair<int, int>>& selected_chickens) {
    int total_distance = 0;
    for (auto& home : homes) {
        int min_distance = INT_MAX;
        for (auto& chicken : selected_chickens) {
            min_distance = min(min_distance, distance(home, chicken));
        }
        total_distance += min_distance;
    }
    return total_distance;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> city(N+1, vector<int>(N+1)); 
    vector<pair<int, int>> chickens; 
    vector<pair<int,int>> homes;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> city[i][j]; 
            if (city[i][j] == 1) { // 집
                homes.push_back({i,j});
            }
            else if (city[i][j] == 2) // 치킨
                chickens.push_back({i,j}); 
        }
    }

    vector<bool> select(chickens.size(), false);
    fill(select.end() - M, select.end(), true);

    int min_city_chicken_distance = INT_MAX;

    do {
        vector<pair<int, int>> selected_chickens;
        for (int i = 0; i < chickens.size(); i++) {
            if (select[i]) {
                selected_chickens.push_back(chickens[i]);
            }
        }

        int current_distance = chicken_distance(homes, selected_chickens);
        min_city_chicken_distance = min(min_city_chicken_distance, current_distance);

    } while (next_permutation(select.begin(), select.end()));

    cout << min_city_chicken_distance;

    return 0;
}
