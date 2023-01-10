#include <string>
#include <vector>
#include <algorithm> 
#include <iostream> 

using namespace std;


struct file {
  string head, num, tail;   
};

bool comp(struct file a, struct file b) {
    string str1, str2;
    for (int i=0; a.head[i]; i++) 
        if (a.head[i] >= 'A' && a.head[i] <= 'Z')
            str1 += a.head[i] +32; 
        else str1 += a.head[i];
    for (int i=0; b.head[i]; i++) 
        if (b.head[i] >= 'A' && b.head[i] <= 'Z')
            str2 += b.head[i] + 32; 
        else str2 += b.head[i];
    
    if (str1 < str2)
    {
        return true;
    }
    else if (str1 > str2)
    {
        return false;
    }
    else
    {
        return stoi(a.num) < stoi(b.num);
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    int size = files.size(); 
    struct file* File = new file[size]; 
    int index, flag;
    
    for (int i=0; i<size; i++) {
        index = 0; 
        flag = 0; 
        for (int j=0; j<files[i].length(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') {
                if (flag == 0) File[i].head = files[i].substr(index, j);
                index = j; 
                File[i].num += files[i][j];
                flag = 1; 
            }
            else if (flag == 1 && (files[i][j] < '0' || files[i][j] > '9')) break;
        }
        File[i].tail = files[i].substr(index+1);
    }

    stable_sort(File, File+size, comp);
    string tmp;
    for (int i=0; i<size; i++) {
        if (File[i].tail[0] != NULL)
            tmp = File[i].head + File[i].num + File[i].tail; 
        else tmp = File[i].head + File[i].num;
        answer.push_back(tmp);  
    }

    delete []File; 
    
    return answer;
}