#include <string>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;
// 점수 계산 방법
// 기본저수 + 링크점수 

struct page {
    int link_num;
    double point; 
    string *url;
    string name; 
};

int solution(string word, vector<string> pages) {
    int answer = 0;
    int len = pages.size(); 
    int size = word.size(); 
    
    transform(word.begin(), word.end(), word.begin(), ::tolower); 

    page *arr = new page[len]; 
    for (int i=0; i<len; i++) {
        arr[i].point = 0; 
        arr[i].link_num = 0; 
        arr[i].url = new string[len];
        for (int j =0; j<len; j++)
            arr[i].url[j] = ""; 
        arr[i].name = "<meta property=\"og:url\" content=\"https://";
    }
    int index,tmp;
    for (int i=0; i<len; i++) {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        index = pages[i].find("<meta property=\"og:url\" content=\"https://"); 

        tmp = arr[i].name.size();
        arr[i].name.clear(); 
        for (int k =index + tmp; ; k++ ) {
            if (pages[i][k] == '\"') break;
            else arr[i].name += pages[i][k];
        }
        int j = 0;
       while (pages[i].find("<a href=\"https://") != string::npos ) {
            index = pages[i].find("<a href=\"https://"); 
            pages[i].erase(pages[i].find("<a href=\"https://"),17);
            tmp = 17;
            for (int k =index; ; k++ ) {
                if (pages[i][k] == '\"') break;
                else arr[i].url[j] += pages[i][k];
            }
            //cout << arr[i].url[j] << endl;
           arr[i].link_num++; 
            j++;
        }
        int start = pages[i].find("<body>"); 
        int end = pages[i].find("</body>");
        string str = pages[i].substr(start+7, end - start - 7);
        int flag = 0; 

        while (str.find(word) != string::npos) {
            int c = str.find(word); 
            //cout << str << endl;
            
            if (c > 0 && ((str[c+size] > 'a' && str[c+size] < 'z') || (str[c-1] > 'a' && str[c-1] < 'z'))) {
                str = str.substr(c +size -1);
                continue;
            }
            else if (c == 0 && str[c+size] > 'a' && str[c+size] < 'z') { 
                str = str.substr(c +size -1);
                continue;
            }  
            arr[i].point++;
            str.erase(str.find(word), size);
        }
        cout << str << endl;
        // cout << "페이지 이름 " << arr[i].name << endl;
        // cout << "기본 점수 : " << arr[i].point << endl;
        // cout << "링크 수 : " << arr[i].link_num << endl;
        // cout << "링크 URL :" << endl;
        // for (int k=0; k<len; k++) 
        //     cout << arr[i].url[k] << " ";
        // cout << endl;
    }
    double max = 0; 
    double p = 0; 
    for (int i=0; i<len; i++) {
        p += arr[i].point;
        for (int j=0; j<len; j++) {
            if (i == j) continue;
            else {
                for (int k =0; k<len; k++) {
                    if (arr[j].url[k] == "") break;
                    else if (arr[j].url[k] == arr[i].name) {
                        p += arr[j].point / arr[j].link_num;
                    }
                }
            }
        }
        // cout << p << endl;
        if (max < p) {
            max = p;
            answer = i;
        }
        p = 0;
    }
    
    for (int i =0; i<len; i++) {
        delete[] arr[i].url; 
    }
    delete[] arr; 
    
    return answer;
}