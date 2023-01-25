import sys

N = int(sys.stdin.readline())

rows = N
cols = 10
a = [ [0 for j in range(cols) ] for i in range(rows) ]

a[0] = [ 0, 1 ,1,1,1,1,1,1,1,1]

for i in range(1,N) :
    for j in range(10) :
        if j == 0 :
            a[i][j] = a[i-1][j+1] #+ a[i-1][j]
        elif j == 9 :
            a[i][j] = a[i-1][j-1] #+ a[i-1][j]
        else :
            a[i][j] = a[i-1][j-1] + a[i-1][j+1] #+ a[i-1][j]



ans = 0
for i in range(10) :
   ans += a[N-1][i]


print(ans % 1000000000)
