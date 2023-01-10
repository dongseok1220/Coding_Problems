#include <string>
#include <iostream>
#include <vector> 

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> arr1; 
    vector<string> arr2; 
    
    int flag = 0;
    for (int i=0; i<str1.length(); i++) {
        if ((str1[i] >='a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i]<='Z')) {
            if (str1[i] >= 'A' && str1[i] < 'a') str1[i] += 'a' - 'A';
            if (flag == 1) arr1.push_back(str1.substr(i-1,2));
            flag = 1;
        }
        else flag = 0 ;
    }
    flag = 0;
    for (int i=0; i<str2.length(); i++) {
        if ((str2[i] >='a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i]<='Z')) {
            if (str2[i] >= 'A' && str2[i] < 'a') str2[i] += 'a' - 'A';
            if (flag == 1 ) arr2.push_back(str2.substr(i-1,2));
            flag = 1;
        }
        else flag = 0; 
    }
    
    double total = arr1.size() + arr2.size(); 
    double same = 0; 
    
    for (int i=0; i<arr1.size(); i++) {
        for (int j=0; j<arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                same++; 
                arr2[j] = "*"; 
                arr1[i] = "#";
            }
        }
    }
    if (total == 0 && same == 0) return 65536; 
    cout << total << " " << same;
    total -= same; 
    double tmp = same / total; 
    answer = int(65536 * tmp); 
    return answer;
}