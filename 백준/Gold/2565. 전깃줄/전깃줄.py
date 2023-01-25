import sys

input = sys.stdin.readline

n = int(input())
point = []

for _ in range(n) :
    point.append(list(map(int,input().split())))

point.sort() 


dp = [1] * n
for i in range(n) :
    for j in range(i) :
        if point[i][1] > point[j][1] and dp[i] < dp[j] + 1 :
            dp[i] = dp[j] + 1


print(n-max(dp)) 
