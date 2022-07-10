import sys

N = int(sys.stdin.readline())


dp = [ [ [-1] * ( 1<< 10) for _ in range(101) ] for _ in range(10) ] 
# bit이용
def find(start, length, bit) :
    if start < 0 or start > 9 :
        return 0

    if length == N :
        return 1 if bit == (1 << 10) -1 else 0

    if dp[start][length][bit] != -1 :
        return dp[start][length][bit]

    dp[start][length][bit] = 0

    if start + 1 < 10 :
        dp[start][length][bit] += find(start+1, length+1, bit | 1 << (start + 1) )
        dp[start][length][bit] %= 1000000000
    if start - 1 >= 0 :
        dp[start][length][bit] += find(start-1, length +1, bit | 1 << (start -1 ))
        dp[start][length][bit] %= 1000000000


    return dp[start][length][bit]



ans = 0

for i in range(1,10) :
    ans += find(i,1, 1 << i)
    ans %=1000000000

print(ans) 
                                        
