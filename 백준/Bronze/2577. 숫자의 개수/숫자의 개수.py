import sys

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())

num = list(map(int,str(a*b*c)))

check = [ 0,0,0,0,0,0,0,0,0,0] # 0~9까지 저장배열 
for i in num :
    check[int(i)] += 1


for i in range(10):
    print(check[i]) 
