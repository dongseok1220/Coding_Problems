#include <string>
#include <vector>
#include <iostream> 

#define comp(a,b) { a > b ? a : b}

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int s, e, t; 
    int len = musicinfos.size(); 
    int m_size = m.size();
    string info, name, lyrics; 
    int j, index;
    int cnt, max = 0; 
    // A# = H C# = I D# = J F# = k
    // CIBCIBCIBCIB
    for (j=1; m[j]; j++) {
        if (m[j] == '#') {
            switch(m[j-1]) {
                case 'A' :
                    m.insert(j+1, "a");
                    break;
                case 'C' :
                    m.insert(j+1, "c");
                    break;
                case 'D' :
                    m.insert(j+1, "d");
                    break;
                case 'F' :
                    m.insert(j+1, "f");
                    break;
                case 'G' :
                    m.insert(j+1, "g");
                    break;
            }
            m.erase(j-1,2);
        }
    }
    //cout << m << endl;
    for (int i=0; i<len; i++) {
        for (j=1; musicinfos[i][j]; j++) {
            if (musicinfos[i][j] == '#') {
                switch(musicinfos[i][j-1]) {
                    case 'A' :
                        musicinfos[i].insert(j+1, "a");
                        break;
                    case 'C' :
                        musicinfos[i].insert(j+1, "c");
                        break;
                    case 'D' :
                        musicinfos[i].insert(j+1, "d");
                        break;
                    case 'F' :
                        musicinfos[i].insert(j+1, "f");
                        break;
                    case 'G' :
                        musicinfos[i].insert(j+1, "g");
                        break;
                }                         
                musicinfos[i].erase(j-1,2);
            }
        }
        //cout << musicinfos[i] << endl;
    }
    
    for (int i=0; i<len; i++) {
        s = stoi(musicinfos[i].substr(0,2)) * 60 + stoi(musicinfos[i].substr(3,2));
        e = stoi(musicinfos[i].substr(6,2)) * 60 + stoi(musicinfos[i].substr(9,2));
        t = abs(e) - abs(s);
        for (j=12; musicinfos[i][j] != ','; j++) 
            name += musicinfos[i][j]; 
        info = musicinfos[i].substr(j+1);
        
        int music_size = info.size(); 
        index = 0; 
        while (t > 0) { 
            if (index >= music_size ) {
                index = 0;
            }
            lyrics += info[index]; 
            index++;
            t--; 
        }
        

        if (lyrics.find(m) != string:: npos) 
            if (max < lyrics.size())
                max = lyrics.length(), answer = name; 
        
        name.clear();
        info.clear();
        lyrics.clear();
    }
    return answer;
}