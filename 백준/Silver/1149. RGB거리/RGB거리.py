import sys
input = sys.stdin.readline

n = int(input())

memo = [0,0,0]
RGB = [] 
for i in range(n) :
    RGB = list(map(int,input().split()))
    temp1 = RGB[0] + min(memo[1],memo[2])
    temp2 = RGB[1] + min(memo[0],memo[2])
    temp3 = RGB[2] + min(memo[1],memo[0])
    memo[0] = temp1
    memo[1] = temp2
    memo[2] = temp3

#print(memo)
print(min(memo)) 
