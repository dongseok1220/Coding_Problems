#include <string>
#include <vector>
#include <iostream> 
#include <iomanip>
#include <algorithm>

using namespace std;

void update_board(vector<vector<int>> &board, int N, int num1, int num2 ) { 
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) 
            if (board[i][j] == 201 || board[i][j] == num1 || board[i][j] == num2) board[i][j] = 0; 
    }

    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            
            if (board[i][j] <= 200 && board[i][j] > 0) {
                if (i >0 && board[i-1][j] <= 200 && board[i-1][j] > 0) continue;
                for (int k = i-1; k > i-3; k--) {
                    if (k < 0) break;
                    board[k][j] = 201;
                }
                break;
            }
        }
    }
}

int check32(vector<vector<int>> &board, int i, int j, int N) {
    vector<int> block; 
    
    int cnt = 0; 
    for (int a=i; a<i+3; a++) {
        for (int b=j; b<j+2; b++) {
            if (board[a][b] == 0) {
                return 0;
            }
            if (board[a][b] == 201) cnt++;
            block.push_back(board[a][b]); 
        }
    }
    if (cnt != 2 ) return 0; 
    sort(block.begin(), block.end());
    block.erase(unique(block.begin(),block.end()),block.end());
    if (block.size() == 2) {
        update_board(board,N,block[0], block[1]);
        return 1;
    }
    return 0; 
}

int check23(vector<vector<int>> &board, int i, int j, int N) {
    vector<int> block; 
    
    int cnt = 0; 
    for (int a=i; a<i+2; a++) {
        for (int b=j; b<j+3; b++) {
            if (board[a][b] == 0) {
                return 0;
            }
            if (board[a][b] == 201) cnt++;
            block.push_back(board[a][b]); 
        }
    }
    if (cnt != 2) return 0; 
    sort(block.begin(), block.end());
    block.erase(unique(block.begin(),block.end()),block.end());
    
    // if (board[i][j] == 1) {
    //     for (int a=0; a<block.size(); a++) 
    //         cout << block[a] << " ";
    // }
    // cout << endl;
    
    if (block.size() == 2) {
        update_board(board,N,block[0], block[1]);
        return 1;
    }
    return 0; 
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int block = 201; // 떨어뜨리는 블록 
    int N = board.size(); 
    int i,j; 
    cout << "이 보드는 " <<  N << " X " << N << " 입니다" << endl;
    update_board(board,N,-1,-1); 
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cout << setw(3) <<  board[i][j] << " "; 
        }
        cout << endl; 
    }
    cout << endl; 
    
    for (int t=0; t<N; t++) {
        for (i = 0; i<N; i++) {
            for (j=0; j<N; j++) {
                if (board[i][j] == 0) continue;
                else { 
                    if (i < N-2 && j < N-1 ) {
                        answer += check32(board,i,j,N);
                    }
                    if (i < N-1 && j < N-2 ) {
                        answer += check23(board,i,j,N); 
                    }
                    update_board(board,N,-1,-1); 
                }
            }
        }   
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cout << setw(3) <<  board[i][j] << " "; 
        }
        cout << endl; 
    }
    
    return answer;
}