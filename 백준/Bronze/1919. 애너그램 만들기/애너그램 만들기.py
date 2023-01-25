import sys
import collections as cols

msetA = sys.stdin.readline().rstrip()
msetB = sys.stdin.readline().rstrip()

msetA = cols.Counter(msetA)
msetB = cols.Counter(msetB)

cnt = msetA - msetB

cnt += msetB - msetA

ans = cnt.values()

ans = sum(ans)

print(ans)
