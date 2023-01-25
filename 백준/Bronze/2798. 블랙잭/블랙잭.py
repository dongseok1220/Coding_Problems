import sys
input = sys.stdin.readline

n,m = map(int,input().split())

card = list(map(int,input().split()))

# 3장을 고르기만하면 된다. 3중포문 구현

ans = 0

for i in range(n) :
    check = card[i]
    for j in range(i+1,n) :
        check += card[j]
        for k in range(j+1,n) :
            check += card[k]
            if check <= m and ans < check :
                ans = check
            if check == m :
                break
            check -= card[k]
            
        if check == m :
            break
        check -= card[j]
    
    if check == m :
        break
        
print(ans)
