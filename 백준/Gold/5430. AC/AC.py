import sys
import re
from collections import deque

input = sys.stdin.readline
n = int(input())

def D(arr):
    global R_cnt
    
    l = len(arr)
    if l == 0 :
        return 0
    if l != 0:
        if R_cnt == 1 :
            arr.pop()
        else :
            arr.popleft()
    return 1

for _ in range(n) :
    R_cnt = 0 
    oper = list(input().rstrip('\n'))
    N = int(input())
    nums = deque()
    string = input().rstrip('\n')
    check = 1
   
    if N >= 1  :
        for i in string[1:-1].split(",") :
            nums.append((i))
    
    for i in oper :
        if i == 'R' :
            R_cnt += 1
        elif i == 'D' :
            check = D(nums)
            if not check :
                break
        R_cnt = R_cnt % 2
    if R_cnt == 1 :
        nums.reverse()
    print("["+",".join(nums) +"]" if check else 'error' )
