import sys
from collections import deque
input = sys.stdin.readline

n,m,r = map(int,input().split()) # n = 정점 수, m= 간선 수, r = 시작 정점
r = r - 1 # 1부터 시작이라 1빼줌 
graph = [ [] for _ in range(n) ] 

for _ in range(m) : 
    s, e = map(int,input().split()) # 시작지점과 종료지점 근데 양방향이므로 end-> start 도 가능함
    graph[s-1].append(e-1)
    graph[e-1].append(s-1)


# 오름차순으로 방문 -> 정렬
for i in graph :
    i.sort(reverse=True)

#print(graph)

visited = [ 0 for _ in range(n) ] # 방문 확인 노드
cnt = 1
stack = deque()
stack.append(r) 

while stack :
    cur = stack.pop()
    if visited[cur] == 0 : # 방문안했으면
        visited[cur] = cnt # 방문 순서
        cnt += 1  
        for i in graph[cur] : # 현재 위치에서 갈 수 있는 노드 탐색
            stack.append(i)

    
for i in visited :
    print(i) 
        
    
