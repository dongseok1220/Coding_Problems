import sys

# dp 이용

dp = [ 0 for _ in range(100) ]

def fibo(n) :
    if n <= 1 :
        return n
    else :
        if dp[n] > 0 :
            return dp[n]

        dp[n] = fibo(n-1) + fibo(n-2)
        return dp[n]


k = int(sys.stdin.readline())

ans = fibo(k)

print(ans)
