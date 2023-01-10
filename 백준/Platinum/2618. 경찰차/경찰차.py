import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
n = int(input())
w = int(input())

event = []
dp = [ [-1 for _ in range(w+1) ]  for _ in range(w+1) ]  # 사건 * 사건  배열

p1 = [(1,1)] # 위치
p2 = [(n,n)] # 위치
ans = [] 
for _ in range(w) :
    i,j = map(int,input().split())
    p1.append((i,j))
    p2.append((i,j))

#거리는 abs(a-i) + abs(b-j)
# event[0] ~ event[w-1] 까지 사건이 존재함

def solve(c1, c2) : # 1번 경찰차 마지막 사건-> c1 , 2번 경찰차 마지막 사건 -> c2
    global w 
    next_c = max(c1,c2) + 1 # 다음 사건번호 
    if next_c == w+1 :
        return 0
    if dp[c1][c2] != -1 :
        return dp[c1][c2] # dp에 값 저장되어 있으면 반환
    # 이 케이스를 해결할 때 더 작은 값을 찾아야함
    police1 = solve(next_c, c2) + distance(p1[c1],p1[next_c] ) # 현재 사건 풀었을 때 거리 + 다음 사건 경우 
    police2 = solve(c1, next_c) + distance(p2[c2],p2[next_c] ) 
    if police1 < police2 : # 더 작은거 값 저장
        dp[c1][c2] = police1
    else :
        dp[c1][c2] = police2
    return dp[c1][c2] # 반환

def distance(p, event) :
    return abs(p[0] - event[0] ) + abs(p[1] - event[1])

print(solve(0,0)) # 0번 0번 시작

def find(c1,c2,dp) :
    global w
    next_c = max(c1,c2) + 1
    if next_c == w+1 :
        return 0

    police1 = dp[next_c][c2] + distance(p1[c1],p1[next_c] )
    police2 = dp[c1][next_c] + distance(p2[c2],p2[next_c] )

    if police1 < police2 : # 더 작은거 값 저장
        print(1)
        find(next_c,c2,dp)
    else :
        print(2)
        find(c1,next_c,dp)

find(0,0,dp)
