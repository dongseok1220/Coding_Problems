import sys

x = [ 0, 1, -1 , 0 ]
y = [ 1, 0, 0 , -1 ]

n, m = map(int, sys.stdin.readline().split())
arr = [ i for i in range(m) ] 

for j in range(n) :
   arr[j] = list(map(int, sys.stdin.readline().split()))


new_arr = arr

print(new_arr) 

arr[0][0] = 4

print(new_arr) 
