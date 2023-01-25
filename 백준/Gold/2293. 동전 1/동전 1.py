import sys
input =sys.stdin.readline
n,k = map(int,input().split())

dp = [0] * (k+1) 
coin =[]
for _ in range(n) :
    coin.append(int(input()))


for i in coin :
    for j in range(i,k+1) :
        if j == i :
            dp[j] = dp[j] + 1
        else :
            index = (j // i ) * i
            dp[j] = dp[j%i + index-i] + dp[j]
            
        
    #print(dp)
    

print(dp[-1])
