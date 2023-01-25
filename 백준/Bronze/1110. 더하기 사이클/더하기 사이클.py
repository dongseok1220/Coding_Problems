import sys

n = int(sys.stdin.readline())

num = []

num.append(int(n/10))
num.append(n%10)

#print(num) 
cnt = 0 
while 1 :
    temp = num[0] + num[1] # 각 자리 숫자 더하기
    temp = int(temp%10) 
    num[0] = num[1] # 오른쪽 자리 수
    num[1] = temp # 합
    cnt += 1
    #print(num)
    if num[0]* 10 + num[1] == n :
        break

print(cnt) 
