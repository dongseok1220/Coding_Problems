import sys
N = int(sys.stdin.readline())
l = sys.stdin.readline().split()
M = int(sys.stdin.readline())


dp = [[ 0 for _ in range(N) ] for _ in range(N) ]

for i in range(N) :
    dp[i][i] = 1
    x = i-1
    y = i+1
    if i+1 <= N-1 and l[i] == l[i+1] :
        dp[i][i+1] = 1
        t = i-1
        k = i+2
        while t >=0 and k <= N-1 :
            if l[t] == l[k] :
                dp[t][k] = 1
            else :
                break
            t = t- 1
            k = k+ 1
    while  x >= 0 and y <= N-1:
        if l[x] == l[y] :
            dp[x][y] = 1
        else :
            break
        x = x-1
        y=  y+1
        
        
for i in range(M):
    flag = 1
    a, b = map(int, sys.stdin.readline().split())
    
    print(dp[a-1][b-1])