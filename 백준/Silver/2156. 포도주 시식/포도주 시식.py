import sys
input = sys.stdin.readline

n = int(input())
wine = [] 
for i in range(n) :
    wine.append(int(input()))
wine.append(0)
wine.append(0)
memo = [0,wine[0],wine[1]+wine[0]]

for k in range(2,n) :
    temp = max( wine[k] + wine[k-1] + memo[k-2], wine[k] + memo[k-1],memo[k]) 
    memo.append(temp)

print(memo[-1]) 
