#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

void swap(string *arr, int a, int b ) {
    string tmp = arr[a]; 
    arr[a] = arr[b];
    arr[b] = arr[a]; 
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int n = cities.size(); 
     vector<string> cache;
    int index = 0;
    
    for (int i=0; i<n; i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        //cout << cities[i] << endl;
    }
    
    int flag = 0; 
    for (int i =0; i<n; i++) {
        for (auto it=cache.begin(); it<cache.end(); it++) {
            if (*it == cities[i]) {
                cache.erase(it);
                cache.push_back(cities[i]);
                answer += 1;
                flag = 1;
                break; 
            }
        }
        if (index < cacheSize && flag == 0) {
            cache.push_back(cities[i]); 
            index++;
            answer += 5; 
        }
        else if (flag == 0) {
            cache.push_back(cities[i]); 
            cache.erase(cache.begin());
            answer += 5; 
        }
        flag = 0; 
    }
 
    return answer;
}