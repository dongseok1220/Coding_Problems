import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int,input().split()))
de = arr[::-1] 

dp = [1] * n
dp2 =[1] * n
for i in range(n) :
    for j in range(i) :
        if arr[i] > arr[j] :
            dp[i] = max(dp[i], dp[j] +1 )
        if de[i] > de[j]  :
            dp2[i] = max(dp2[i],dp2[j]+1) 

result = [0] * n
for i in range(n) :
    result[i] = dp[i] + dp2[n-i-1] - 1

print(max(result))




