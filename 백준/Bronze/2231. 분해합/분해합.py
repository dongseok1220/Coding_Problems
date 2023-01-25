import sys

input = sys.stdin.readline

# a = b + b1 .... + bn 이 된다. (bi 는 각 자릿수)

n = input()

l = len(n) -1 

n = int(n)

k = 9*l

ans = n - k
if ans < 0 :
    k = n
    ans = 0

check = 0

flag = 0
while k >= l  and ans >=0:
    k -= 1
    atoi = str(ans)
    check = ans
    for i in range(len(atoi)) :
        check += int(atoi[i])
    if check == n:
        print(ans)
        flag = 1
        break
    else :
        ans = n -k

if flag == 0 :
    print(0)
