import sys
from collections import deque

# 일반적인 방법으로는 시간초과가 난다

dx,dy = [1, -1, 0, 0],[0, 0, 1, -1] # 방향

def bfs(lake, visited, queue):
    q_next = deque() # 정보 저장 큐
    while queue:
        y,x = queue.popleft()
        #print(y,x) 
        if x == swan[1][1] and y == swan[1][0]: # 백조 발견
            return 1, None 
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i] 
            if 0 <= nx < c and 0 <= ny < r: # 범위
                if visited[ny][nx] == 0 : # 방문안한 곳
                    if lake[ny][nx] == 'X':
                        q_next.append((ny, nx)) # 다음에 확인해야하는 곳
                    else:
                        queue.append((ny, nx)) # 물이면 이동함
                    visited[ny][nx] = 1


    return 0, q_next

def melt(lake, water) :
    w_next = deque() 
    while water :
        y,x = water.popleft() # 현재 물인 지점의 좌표
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < c and 0 <= ny < r: # 범위 
                if lake[ny][nx] == 'X': # 녹아야 함 
                    w_next.append((ny,nx)) # 물의 좌표 저장함
                    lake[ny][nx] = '.'
                    
    return w_next

r,c = map(int, sys.stdin.readline().split())

lake = []
water = deque()
swan = []

for i in range(r) :
    temp = list(sys.stdin.readline().strip()) # 한줄 입력받기
    for j,k in enumerate(temp) : # tuple
        if k == '.' or k == 'L' : # 물이거나 백조면
            water.append((i,j)) # i,j append
        if k == 'L' : # 그리고 백조 위치 저장해주어야함
            swan.append((i,j))
    lake.append(temp) # 그리고 호수

day = 0 # 날짜 변수
visited = [[0] * c for _ in range(r)] # 방문 리스트

queue = deque() # deque 생성

y,x = swan[0][0] , swan[0][1] # 백조 위치
queue.append((y,x)) # 시작하기 전 변수 할당
visited[y][x] = 1
#print(swan)

while 1 :
    check, next_q = bfs(lake,visited,queue)
    #print(lake)
    if check == 1 :
        break
    day += 1

    water = melt(lake, water)
    queue = next_q

print(day) 
            
