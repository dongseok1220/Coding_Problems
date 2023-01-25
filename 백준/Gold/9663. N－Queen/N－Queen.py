import sys
input = sys.stdin.readline

n = int(input())

ans = 0 # 정답

field = [ 0 ] * n  # index와 그 값을 이용해 2차원배열처럼 사용함


def sol(cur) :
    global ans
    if cur == n : # 다 놓았으면 정답 1c추가 
        ans += 1
        return
    else :
        for i in range(n) : # 0~n-1 줄에놓음
            field[cur] = i # cur,i에 퀸 놓음
            if update(cur) : # 놓을 수 있으면 다음줄에 놓음 
                sol(cur+1)

def update(cur) :
    for i in range(cur) : # 어디에 놓을 수 있는지 확인 
        if field[cur] == field[i] or abs(field[cur]-field[i]) == abs(cur-i) : # 같은 줄에 있거나 대각선 확인을 절대값을 이용해 확인함
            return 0
    return 1
                
sol(0) 
print(ans) 
        

