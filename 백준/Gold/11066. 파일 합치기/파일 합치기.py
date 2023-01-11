import sys
input = sys.stdin.readline

n = int(input())

dp = [[0 for _ in range(501)] for _ in range(501) ] # 2차원배열

for _ in range(n) :
    arr = []
    num = int(input()) # 배열 길이
    arr = list(map(int,input().split()))
    sum_ = [0] * (num+1)
    sum_[0] = arr[0]
    for i in range(1,num) :
        sum_[i] = sum_[i-1] + arr[i]

    for i in range(num) :
        for j in range(num-i-1) :
            dp[j][i+j+1] = float('inf')
            for k in range(j,i+j+1) :
                if i == 0 and j == 0 :
                    dp[0][1] = sum_[1]
                dp[j][i+j+1] = min(dp[j][i+j+1] , dp[j][k]+dp[k+1][i+j+1]+sum_[i+j+1]-sum_[j-1])
    #for i in range(num) :
        #print(dp[i][:num+1])

    print(dp[0][num-1])
