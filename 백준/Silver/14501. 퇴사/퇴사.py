import sys
input = sys.stdin.readline

n = int(input())

work = [list(map(int,input().split())) for _ in range(n)]
work.append([0,0])

ans = [0] * (n+1)


i,j = 0,0
max_is = 0
temp = 0

''' 정방향으로 풀면 반례가 존재함 
for i in range(n) :
    j = i 
    while j < n :
        if j + work[j][0] > n :
            break
        ans[i][j] = work[j][1] + temp
        temp = ans[i][j]
        j += work[j][0]
        
    if max_is < temp :
        max_is = temp
    temp = 0 
    j = 0
'''

for i in range(n-1,-1,-1) : 
    if i + work[i][0] > n : # n일 보다 커지면 선택 못함
        work[i][1] = work[i+1][1]
        continue
    else :
        work[i][1] = max(work[i+1][1], work[i][1]+work[i+work[i][0]][1])

print(work[0][1])

    
