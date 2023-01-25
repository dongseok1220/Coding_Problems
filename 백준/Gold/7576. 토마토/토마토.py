import sys
from collections import deque

input = sys.stdin.readline

dx,dy = [1, -1, 0, 0],[0, 0, 1, -1] # 방향

M,N = map(int,input().split())

graph = []
tomato = deque()
visited = [ [ 0 ] * M for _ in range(N) ]

for i in range(N) :
    temp = (list(map(int,input().split())))
    for j,k in enumerate(temp) :
        if k == 1 :
            tomato.append((i,j))
        elif k == -1 :
            visited[i][j] = 1
    graph.append(temp)


def make_tomato(graph, tomato,visited) :
    t_next = deque()
    while tomato :
        y,x = tomato.popleft()
        for i in range(4) :
            nx = x +dx[i]
            ny = y +dy[i]
            if 0 <= nx < M and 0 <=ny < N :
                if graph[ny][nx] == 0 :
                    visited[ny][nx] = 1
                    t_next.append((ny,nx))
                    graph[ny][nx] = 1

    return t_next

day = 0
while 1 :
    tomato = make_tomato(graph,tomato,visited)
    if len(tomato) ==0 :
        break
    day += 1

flag = 0 
for i in graph :
    if 0 in i :
        print(-1)
        flag = 1
        break

if flag == 0 :
    print(day)
