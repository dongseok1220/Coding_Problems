#include <string>
#include <vector>
#include <iostream>

using namespace std;

string binary(int a, int n) {
    // 1 == '#'
    int *bin = new int[n]; 
    int index = n-1; 
    string tmp; 
    for (int i=0; i<n; i++) 
        bin[i] = 0;
    while (a >= 1) {
        bin[index] = a % 2;
        a = a / 2;  
        index--; 
    }
    for (int i=0; i<n; i++) {
        if (bin[i] == 1) tmp += '#'; 
        else tmp += ' '; 
    }
    delete [] bin; 
    return tmp; 
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tmp; 
    // for (int i=0; i<n; i++) {
    //     cout << arr1[i] << " " << binary(arr1[i], n) << endl; 
    //     //cout << arr2[i] << " " << binary(arr2[i], n) << endl; 
    // }
    // for (int i=0; i<n; i++) {
    //     //cout << arr1[i] << " " << binary(arr1[i], n) << endl; 
    //     cout << arr2[i] << " " << binary(arr2[i], n) << endl; 
    // }
    for (int i=0; i<n; i++) {
        answer.push_back(binary(arr1[i], n));
    }
    for (int i=0; i<n; i++) {
        tmp = binary(arr2[i], n); 
        for (int j=0; j<n; j++) {
            if (tmp[j] == '#') answer[i][j] = '#'; 
        }
    }
    return answer;
}