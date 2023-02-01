#include <string>
#include <vector>
#include <deque> 
#include <algorithm>
#include <iostream> 

#define MIN(a,b) { a > b ? b : a}

using namespace std;

struct pos {
    int r,c;
    int ans;
};

int find(int i,int start_r, int start_c, int target_r, int target_c, vector<vector<int>> &board)
{
    //cout << "탐색 " << endl;
    
    int cnt = 0; 
    int dr[4] = {-1,1,0,0}; // 위 아래 좌 우
    int dc[4] = {0,0,-1,1}; 
    
    deque<pos> start;
    start.push_front({start_r,start_c,0});
    
    int visit[4][4] = {0,}; 
    visit[start_r][start_c] = 1; 
    if (start_r == target_r && start_c == target_c) return 0; 
    
    while (start.size() != 0 ) {
        pos cur = start.front();
        start.pop_front(); 
        // 상하좌우 push 
         //cout << "현재 위치 : "; 
         //cout << cur.r << " " << cur.c << " " << cur.ans << endl;
        if (cur.r == target_r && cur.c == target_c) {
            return cur.ans; // Enter 2번 
        }
        
        //cout << "탐색위치 : " << endl;
        for (int i=0; i<4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            
            if (nr > 3 || nc > 3 || nr < 0 || nc < 0) continue;
            if (visit[nr][nc]) continue; 
            //cout << nr << " " << nc << " " << cur.ans+1 << endl;
            if (board[nr][nc])
                start.push_back({nr,nc,cur.ans+1});
            else start.push_back({nr,nc,cur.ans+1});
            visit[nr][nc] = 1; 
        }
        
        // crtl 누른 상태 push 
        for (int i=0; i<4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i]; 
            
            if (nr > 3 || nc > 3 || nr < 0 || nc < 0) continue;
            if (board[nr][nc]) continue; 
            
            if (i==0) { // 위 
                while (nr > -1) {
                    if (nr > 3 || nc > 3 || nr < 0 || nc < 0) break;
                    if (!visit[nr][nc] && (board[nr][nc] || nr == 0)) { // 카드를 만나거나 최하단으로 가면 멈춤 
                        start.push_back({nr,nc,cur.ans+1});
                        visit[nr][nc] = 1;
                        //cout << nr << " " << nc << " " << cur.ans+1 << endl;
                        break;
                    }
                    //visit[nr][nc] = 1;
                    nr += dr[i];
                }
            }
            else if (i==1) {
                while (nr < 4) {
                    if (nr > 3 || nc > 3 || nr < 0 || nc < 0) break;
                    if (!visit[nr][nc] && (board[nr][nc] || nr == 3)) { // 카드를 만나거나 최하단으로 가면 멈춤 
                        start.push_back({nr,nc,cur.ans+1});
                        visit[nr][nc] = 1;
                        //cout << nr << " " << nc << " " << cur.ans+1 << endl;
                        break;
                    }
                    //visit[nr][nc] = 1;
                    nr += dr[i];
                }
            }
            else if (i==2) {
                while (nc > -1) {
                    if (nr > 3 || nc > 3 || nr < 0 || nc < 0) break;
                    if (!visit[nr][nc] && (board[nr][nc] || nc == 0)) { // 카드를 만나거나 최하단으로 가면 멈춤 
                        start.push_back({nr,nc,cur.ans+1});
                        visit[nr][nc] = 1;
                        //cout << nr << " " << nc << " " << cur.ans+1 << endl;
                        break;
                    }
                    //visit[nr][nc] = 1;
                    nc += dc[i];
                }
            }
            else {
                while (nc < 4) {
                    if (nr > 3 || nc > 3 || nr < 0 || nc < 0) break;
                    if (!visit[nr][nc] && (board[nr][nc] || nc == 3)) { // 카드를 만나거나 최하단으로 가면 멈춤 
                        start.push_back({nr,nc,cur.ans+1});
                        visit[nr][nc] = 1;
                        //cout << nr << " " << nc << " " << cur.ans+1 << endl;
                        break;
                    }
                    //visit[nr][nc] = 1;
                    nc += dc[i];
                }
            }
        }

    }
    return 0;
}

int num, ans; 

int back_track(int depth, vector<int> perm, int r, int c, vector<vector<int>> board, int cnt, vector<vector<pair<int,int>>> card) {
    if (depth == num) return cnt; 
    int i = perm[depth]; // 뽑을 카드 
    vector<vector<int>> tmp = board; 
    int case1 = find(i,r,c,card[i][0].first ,card[i][0].second, tmp) + find(i,card[i][0].first, card[i][0].second, card[i][1].first, card[i][1].second, tmp) + 2; 
    int case2 = find(i,r,c,card[i][1].first ,card[i][1].second, tmp) + find(i,card[i][1].first, card[i][1].second, card[i][0].first, card[i][0].second, tmp) + 2;
    
    tmp[card[i][0].first][card[i][0].second] = 0; 
    tmp[card[i][1].first][card[i][1].second] = 0; 
    
    if (case1 < case2) { 
        return back_track(depth+1, perm, card[i][1].first, card[i][1].second, tmp, cnt + case1, card);
    }
    else {
        return back_track(depth+1, perm, card[i][0].first, card[i][0].second, tmp, cnt + case2, card);
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 10000000;
    vector<vector<pair<int,int>>> card(7); 
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (board[i][j] != 0 ) 
                card[board[i][j]].push_back(make_pair(i,j));
            if (board[i][j] > num) num = board[i][j];
        }
    }
    vector<int> perm; 
    for (int i=1; i<= num; i++) 
        perm.push_back(i); 
    
    do {
        answer = MIN(answer , back_track(0, perm, r, c, board, 0, card));
    } while (next_permutation(perm.begin(), perm.end()));
    
    return answer;
}