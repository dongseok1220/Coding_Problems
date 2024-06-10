#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip> 

using namespace std;

int N;
int card[1000001] = {0,}; 
int players[1000001] = {0,}; 

int main() {
    cin >> N; 

    vector<int> numbers(N+1); 

    for (int i=1; i<=N; i++) {
        cin >> numbers[i];
        card[numbers[i]] = 1;
    } 

    for (int i=1; i<=N; i++) {
        for (int j=numbers[i] * 2; j <= 1000000; j += numbers[i]) {
            if (card[j] == 0) continue; 
            else { 
                players[numbers[i]]++;
                players[j]--; 
            }
        }
    }

    for (int i=1; i<=N; i++) {
        cout << players[numbers[i]] << " ";
    }
    return 0;
}
