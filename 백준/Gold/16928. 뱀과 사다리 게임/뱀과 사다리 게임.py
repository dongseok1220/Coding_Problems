import sys
from collections import deque

input = sys.stdin.readline

n,m = map(int,input().split())

ladder = deque()
for i in range(n) :
    x,y = map(int,input().split())
    ladder.append((x,y)) # x -> y


snake = deque()
for i in range(m) :
    u,v = map(int,input().split())
    snake.append((u,v)) # u -> v

cur = deque()
cur.append(1)

_map = [0]  * 101 # 1부터 시작
_map[1] = 1 
cnt = 0
while cur :
    #print(cur)
    x = cur.popleft()
    if x >= 100 :
        break
    for i in range(1,7) :
        if x+i <= 100 and _map[x+i] == 0 :
            _map[x+i] = _map[x]+1
            cur.append(x+i)
            for k in ladder :
                if k[0] == x+i :
                    cur.pop()
                    cur.append(k[1])
                    if _map[k[1]] == 0:
                        _map[k[1]] = _map[x] + 1
                    break
            for j in snake :
                if j[0] == x+i :
                    cur.pop()
                    cur.append(j[1])
                    if  _map[j[1]] == 0 : 
                        _map[j[1]] = _map[x] + 1
                    break

print(_map[100]-1)
    
        
        
        
