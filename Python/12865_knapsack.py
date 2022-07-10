import sys

N, K = map(int, input().split())
arr = [[0,0]]
knapsack = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for _ in range(N):
    arr.append(list(map(int, input().split())))

for i in range(1, N + 1):
    for j in range(1, K + 1):
        weight = arr[i][0] 
        value = arr[i][1]
       
        if j < weight:
            knapsack[i][j] = knapsack[i - 1][j] 
        else:
            knapsack[i][j] = max(value + knapsack[i - 1][j - weight], knapsack[i - 1][j])

print(knapsack[N][K])

