import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))
oper = list(map(int,input().split()))

# oper 는 + - x / 순

ans_M = -1000000000 # 최대 
ans_m = 1000000000 # 최소

def cal(plus ,minus, mult, divide, ans, cnt,n) :
    global ans_m, ans_M
    if cnt == n :
        ans_M = max(ans_M, ans)
        ans_m = min(ans_m, ans)
        return
    else :
        num = a[cnt]
        if plus > 0 :
            temp = ans + num
            cal(plus-1,minus, mult,divide, temp,cnt+1, n)
        if minus >0:
            temp = ans - num
            cal(plus,minus-1, mult,divide, temp,cnt+1, n)
        if mult > 0 :
            temp = ans * num
            cal(plus,minus, mult-1,divide, temp,cnt+1, n)
        if divide > 0:
            temp= int(ans / num)
            cal(plus,minus, mult,divide-1, temp,cnt+1, n)

num = a[0]
cal(oper[0],oper[1],oper[2],oper[3],num,1,n)
print(ans_M)
print(ans_m)
