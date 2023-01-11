import sys
from collections import deque

r,c = map(int, sys.stdin.readline().split())

ice = [ list(map(int,sys.stdin.readline().split())) for _ in range(r) ]

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

day = 0

n_list = [[0] * c for _ in range(r)]
visited = [[0] * c for _ in range(r)] # 방문리스트
deq = deque() # 양방향

def melt() :
    for i in  range(r) :
        for j in range(c) :
            if ice[i][j] != 0 :
                for k in range(4) :
                    nx = i + dx[k]
                    ny = j + dy[k]
                    if 0 <= nx < r and 0 <= ny < c and ice[nx][ny] == 0 :
                        n_list[i][j] += 1


def bfs(a,b) :
    deq.append((a,b)) # 쌍으로 append함
    while deq :
        i,j = deq.popleft() # 큐의 pop
        visited[i][j] = 1 # 방문 표시
        for k in range(4) :
                nx = i + dx[k]
                ny = j + dy[k]
                if 0 <= nx < r and 0 <= ny < c and ice[nx][ny] != 0 and visited[nx][ny] == 0 :
                    visited[nx][ny] = 1 
                    deq.append((nx,ny)) # 원소 추가 

        
        
while(1) :
    melt() # 녹임
    for i in range(r) :
        for j in range(c) :
            ice[i][j] -= n_list[i][j]
            n_list[i][j] = 0 # 초기화
            visited[i][j] = 0 
            if ice[i][j] < 0 :
                ice[i][j] = 0
    cnt = 0
    for i in range(r) :
        for j in range(c) :
            if ice[i][j] != 0 and visited[i][j] == 0 :
                cnt += 1
                bfs(i,j)
    #print(cnt)
    #print(ice)
    #print(visited)
    if cnt > 1 :
        break
    if cnt == 0 :
        break
    day += 1


if cnt > 1 :
    print(day+1)
else :
    print(0)
