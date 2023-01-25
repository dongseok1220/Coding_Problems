import sys
input = sys.stdin.readline

n = int(input())

memo = [0] * n
arr = []
temp = [0] * n
for i in range(n) :
    arr = (list(map(int,input().split())))
    for j in range(len(arr)) :
        if j == 0 :
            memo[j] = temp[j] + arr[j] 
        elif j == len(arr)-1 :
            memo[j] = temp[j-1] + arr[j]
        else :
            memo[j] = max(temp[j-1]+arr[j] , temp[j]+arr[j])
    for j in range(n) :
        temp[j] = memo[j]
        
    #print(memo)

print(max(memo)) 
