import sys

h,m = map(int,sys.stdin.readline().split())

if m >= 45 :
    m = m - 45
elif m < 45 :
    if h == 0 :
        h = 23
        m = m + 60 -45
    else :
        h = h - 1
        m = m + 60 - 45

print(h,m) 
