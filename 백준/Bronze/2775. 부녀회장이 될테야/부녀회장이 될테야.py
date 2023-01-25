import sys

case = int(sys.stdin.readline())

f = [[0 for i in range(14) ] for j in range(15)]

for i in range(14) :
    f[0][i] = i+1
    
for i in range(14) :
    temp = 0
    for j in range(14) :
        temp += f[i][j]
        f[i+1][j] = temp

for i in range(case) :
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    print(f[a][b-1])    


