import sys

is_min = 100 # 입력되는 수는 항상 100보다 작음
is_sum = 0

for i in range(7) :
    num = int(sys.stdin.readline())
    if num % 2 == 1 : # 홀수
        is_sum += num
        if is_min > num :
            is_min = num



if is_sum == 0 and is_min ==100 :
    print(-1)
else :
    print(is_sum)
    print(is_min)
