import sys
import heapq

N = int(sys.stdin.readline())

left = []
right = []

for i in range(N) :
    num = int(sys.stdin.readline())
    if len(left) == len(right) :
        heapq.heappush(left,-num) 
    else :
        heapq.heappush(right,num) 
    if right and right[0] < -left[0] :
        l_value = heapq.heappop(left)
        r_value = heapq.heappop(right)

        heapq.heappush(left, -r_value)
        heapq.heappush(right, -l_value)
    print(-left[0]) 

