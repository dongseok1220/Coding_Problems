import sys
input = sys.stdin.readline

n = int(input())

def star(i,j,n) :
    if  (i // n ) % 3 == 1 and (j // n) % 3 == 1:
        print(" ",end='')
    else :
        if n // 3 == 0 :
            print("*",end='')
        else :
            star(i,j,n//3)
    

for i in range(n) :
    for j in range(n) :
        star(i,j,n)
    print()

    
