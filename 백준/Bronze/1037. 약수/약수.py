import sys

n = int(sys.stdin.readline())

divisor = list(map(int,sys.stdin.readline().split()))
#print(divisor)

''' 잘못 된 풀이
while 1 :
    num = divisor[0] * k # 구해야하는 N은 아무리 작아도 어떤 약수의 2배 이상이다.
    k = k + 1 # k 증가
    for i in range(n) :
        if num == divisor[i] :
            flag = 1 # 약수 != N 체크 
            break
        if num % divisor[i] != 0 :
            break

    if i == n-1 and flag != 1:
        break
    
    flag = 0 
'''

# 약수의 개수가 홀수이거나 짝수로 나눔
#cnt = len(divisor) 이게 그냥 n임..
s_div = sorted(divisor)
#print(s_div)
if n % 2 == 0 : # 짝수면
    num = s_div[0] * s_div[n -1]
else :
    if n == 1 :
        num = s_div[0] * s_div[0] 
    else :
        n = int(n/2)
        num = s_div[n] * s_div[n]

print(num)
