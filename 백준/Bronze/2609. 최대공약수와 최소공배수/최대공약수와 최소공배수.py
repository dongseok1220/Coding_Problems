import sys

n,k = map(int,sys.stdin.readline().split())

# using 유클리드 호제법

def gcd(a,b) :
    if b == 0 :
        return a
    else :
        return gcd(b,a%b)


ans1 = gcd(n,k)

print(ans1)
print(int(n*k / ans1) )

